// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
using namespace std;
typedef pair<int, int> p;

vector<vector<char>> map;
string cmd;
p player_pos;
bool dead_by_boss = false;
// p boss_pos;

struct status {
    string name = "RPG Extreme";
    int x, y;

    // 체력, 방어력, 공격력, 경험치;
    int hp, df, atk, exp;
    int max_hp;

    status() {};
    status(int x, int y, int hp, int df, int atk, int exp, string name = "RPG Extreme") :
        name(name), x(x), y(y), hp(hp), df(df), atk(atk), exp(exp), max_hp(hp) {}
};

/**
 * 플레이어 클래스
 * status 클래스를 상속받음
*/
class player :status {
private:
    int level = 1;
public:
    int weapon = 0; //무기^
    int armor = 0; //방어구^
    set<string> inventory;//현재 가지고 있는 아이템 목록^
    bool HR = false; //HP 회복^
    bool RE = false; //부활 능력^
    bool HU = false; //보스전 관련 능력^
    bool DX = false; //CO, 가시함정 데미지 감소^
    int CO = 1; //용기, DX 능력^
    double EX = 1; //경험치 증가율^
    //^:box 객체가 변경
    // set<string> inventory;

    /**
     * 생성자
    */
    player(int x, int y, int hp, int df, int atk, int exp, string name = "RPG Extreme") :
        status(x, y, hp, df, atk, exp, name) {}

private:

    /**
     * 경험치를 추가하는 함수
     * 경험치가 5 * level 이상이면 레벨업
     * 레벨업시 최대 체력 5, 공격력 2, 방어력 2 증가
     * 경험치는 0으로 초기화
     * @param exp 추가할 경험치
    */
    void add_exp(int exp) {
        this->exp += trunc(exp * EX);//EX가 있을 경우 경험치 20% 증가
        if (this->exp >= 5 * level) {
            level++;
            max_hp += 5;
            atk += 2;
            df += 2;
            hp = max_hp;
            this->exp = 0;
        }
    }

    /**
     * 부활 능력을 사용하는 함수
     * 부활 능력이 있을 경우 체력을 최대 체력으로 회복
     * 부활 능력이 있을 경우 부활 능력을 삭제
     * @return 부활 능력이 있을 경우 true, 없을 경우 false
     * @see RE
     * @see inventory
    */
    bool reincarnation() {
        if (RE) {
            hp = max_hp;
            RE = false;
            inventory.erase("RE");
            return true;
        }
        else {
            return false;
        }
    }

    /**
     * 공격력을 반환하는 함수
     * 무기 능력이 있을 경우 무기 능력을 추가하여 반환
    */
    int get_atk() {
        return (atk + weapon);
    }

    /**
     * 방어력을 반환하는 함수
     * 방어구 능력이 있을 경우 방어구 능력을 추가하여 반환
    */
    int get_df() {
        return df + armor;
    }

public:
    /**
     * 반환 인자에 대한 설명
     * -2: 사망함, 잡몹
     * -3: 보스관련
     * -4: 스파이크
    */

    /**
     * 몬스터와 싸우는 함수
     * 둘중 하나의 체력이 0이하가 될 때까지 싸움
     * @param monster 몬스터의 상태
     * @param pos 플레이어의 위치
     * @return 플레이어의 위치
     * 전투에서 이길경우: 정상적으로 전투가 끝난 위치
     * 전투에서 졌을 경우:
     *      - 부활 능력이 있을 경우: 부활 능력을 사용하여 시작 위치로 이동
     *      - 부활 능력이 없을 경우: {-2, -2} 반환
    */
    p fight(status& monster, p pos) {

        for (int cnt = 1; cnt > 0; cnt++) {
            if (cnt == 1) monster.hp -= max(1, get_atk() * CO - monster.df);
            else monster.hp -= max(1, get_atk() - monster.df);
            if (monster.hp <= 0) {
                add_exp(monster.exp);
                if (HR) ((hp + 3) > max_hp ? hp = max_hp : hp+=3); //HR능력
                return pos;
            }
            hp -= max(1, monster.atk - get_df());
            if (hp <= 0) {
                if (reincarnation()) {
                    monster.hp = monster.max_hp;
                    return player_pos;
                }
                return { -2, -2 };
            }
        }
        return pos;
    }

    /**
     * 보스와 싸우는 함수
     * 둘중 하나의 체력이 0이하가 될 때까지 싸움
     * @param boss 보스의 상태
     * @param pos 플레이어의 위치
     * @return 플레이어의 위치
     * 전투에서 이길경우: {-3, -3} <- 게임 종료
     * 전투에서 졌을 경우:
     *    - 부활 능력이 있을 경우: 부활 능력을 사용하여 시작 위치로 이동
     *    - 부활 능력이 없을 경우: {-2, -3} 반환
    */
    p boss_fight(status& boss, p pos) {
        if (HU) {
            hp = max_hp;
        }

        for (int cnt = 1; cnt > 0; cnt++) {
            if (cnt == 1) boss.hp -= max(1, get_atk() * CO - boss.df);
            else boss.hp -= max(1, get_atk() - boss.df);
            if (boss.hp <= 0) {
                add_exp(boss.exp);
                if (HR) ((hp + 3) > max_hp ? hp = max_hp : hp+=3); //HR능력
                return { -3, -3 };
            }
            if (cnt == 1 && HU) continue;
            else hp -= max(1, boss.atk - get_df());
            if (hp <= 0) {
                if (reincarnation()) {
                    boss.hp = boss.max_hp;
                    return player_pos;
                }
                dead_by_boss = true;
                return { -2, -3 };
            }
        }
        return pos;
    }

    /**
     * 함정에 걸렸을 때 실행되는 함수
     * @param pos 플레이어의 위치
     * @return 플레이어의 위치
     * 부활 능력이 있을 경우: 부활 능력을 사용하여 시작 위치로 이동
     * 부활 능력이 없을 경우: {-2, -4} 반환
    */
    p spike_trap(p pos) {
        if (DX) hp -= 1;
        else hp -= 5;

        if (hp <= 0) {
            if (reincarnation()) {
                hp = max_hp;
                return player_pos;
            }
            return { -2, -4 };
        }

        else return pos;
    }

    void print_player_status() {
        cout << "LV : " << level << '\n';
        cout << "HP : " << (hp < 0 ? 0 : hp) << '/' << max_hp << '\n';
        cout << "ATT : " << atk << '+' << weapon << '\n';
        cout << "DEF : " << df << '+' << armor << '\n';
        cout << "EXP : " << exp << '/' << 5 * level << '\n';
    }
};

/**
 * 상자 객체
 * 아이템이 들어있는 상자와 무기, 방어구가 들어있는 상자를 구분하기 위해
 * 생성자를 2개 만들었다.
 * 아이템이 들어있는 상자는 item_box_playerValue_changer 함수를 통해
 * 플레이어의 능력치를 변경시킨다.
 * 무기, 방어구가 들어있는 상자는 weapon_box_playerValue_changer 함수를 통해
 * 플레이어의 능력치를 변경시킨다.
*/
class box {
private:
    string title = "";
    int power = -1;
    string item;

public:

    // 기본 생성자
    box() {};

    // 아이템이 들어있는 상자를 위한 생성자
    box(string title, string item) : title(title), power(-1), item(item) {}

    // 무기 또는 방어구가 들어있는 상자를 위한 생성자
    box(string title, int power) : title(title), power(power), item("") {}

private:
    void item_box_playerValue_changer(player& player) {
            if (item == "HR") {
                //HP 회복
                player.HR = true;
            }
            else if (item == "RE") {
                player.RE = true;
            }
            else if (item == "HU") {
                player.HU = true;
            }
            else if (item == "DX") {
                if (player.CO == 2) player.CO = 3;
                player.DX = true;
            }
            else if (item == "EX") {
                player.EX = 1.2;
            }
            else if (item == "CO") {
                player.CO = 2;
            }
        }

        void weapon_box_playerValue_changer(player& player) {
            if (title == "W") {
                player.weapon = power;
            }
            else if (title == "A") {
                player.armor = power;
            }
        }

public:
    //주인공 객체의 주소를 할당 받아 변경함
    void open(player& player) {
        if (item != "" && player.inventory.size() < 4) {
            //cout << player.inventory.size() << "<------------------------------------------\n";
            //상자에 아이템이 있고 인벤토리가 꽉 차지 않았을 경우 
            item_box_playerValue_changer(player);
            player.inventory.insert(item);
        }
        else {
            weapon_box_playerValue_changer(player);
        }
    }
};

/**
 * 스파이크, 몬스터, 상자의 위치를 저장하기 위한 자료구조
*/
struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

unordered_map<p, status, pairhash> monster_info;
unordered_map<p, box, pairhash> box_info;
set<p> spike_pos;

/**
 * 입력을 받는 함수
*/
void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, mon_cnt = 0, box_cnt = 0;
    cin >> n >> m;
    map.resize(n);

    for (int i = 0; i < map.size(); i++) {
        map[i].resize(m);
        for (int j = 0; j < map[i].size(); j++) {
            cin >> map[i][j];
            if (map[i][j] == '&') {
                mon_cnt++;
            }
            else if (map[i][j] == 'B') {
                box_cnt++;
            }
            else if (map[i][j] == '^') {
                spike_pos.insert({ j, i });
            }
            else if (map[i][j] == '@') {
                player_pos = { j, i };
            }
            // else if (map[i][j] == 'M'){
            //     boss_pos = {j, i};
            // }
        }
    }

    cin >> cmd;

    for (int i = 0; i < mon_cnt + 1; i++) {
        string name;
        int x, y, hp, df, atk, exp;
        cin >> y >> x >> name >> atk >> df >> hp >> exp;
        monster_info[{x - 1, y - 1}] = status(x, y, hp, df, atk, exp, name);
    }

    for (int i = 0; i < box_cnt; i++) {
        string option;
        int x, y;
        cin >> y >> x >> option;
        if (option == "O") {
            string item;
            cin >> item;
            box_info[{x - 1, y - 1}] = box(option, item);
        }
        else {
            int power;
            cin >> power;
            box_info[{x - 1, y - 1}] = box(option, power);
        }
    }
}

/**
 * 지도 출력 함수
*/
void map_print() {
    for (auto& i : map) {
        for (auto& j : i) {
            cout << j;
        }
        cout << '\n';
    }
}

/**
 * 솔루션 함수
*/
void solution() {
    int turn = 0;
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };
    int d_idx = 0;
    int nx = player_pos.first;
    int ny = player_pos.second;
    int cx, cy;
    string end_message = "Press any key to continue.";
    status monster = status(0, 0, 0, 0, 0, 0); // init
    player ply = player(player_pos.first, player_pos.second, 20, 2, 2, 0);
    p result;

    for (auto& i : cmd) {
        /**
         * 1. 이동
        */
        switch (i) {
        case 'U':
            d_idx = 3;
            break;
        case 'D':
            d_idx = 2;
            break;
        case 'R':
            d_idx = 0;
            break;
        case 'L':
            d_idx = 1;
            break;
        default:
            break;
        }

        cx = nx + dx[d_idx];
        cy = ny + dy[d_idx];

        /**
         * to - do
         * 2. 칸의 종류 판별
         * 2-1. 몬스터
         * 2-2. 상자
         * 2-3. 빈칸
         * 2-4. 보스
         * 2-5. 함정
         * 2-5. 벽
        */
        if (cx < 0 || cy < 0 || cx >= map[0].size() || cy >= map.size()) {
            if (spike_pos.count({ nx, ny })) {
                result = ply.spike_trap({ nx, ny });
                monster.name = "SPIKE TRAP";
            }
        }
        else if (map[cy][cx] == '&') { // 몬스터
            monster = monster_info[{cx, cy}];
            result = ply.fight(monster, { cx, cy });
        }
        else if (map[cy][cx] == 'B') { // 상자
            box& box = box_info[{cx, cy}];
            box.open(ply);
            result = { cx, cy };
        }
        else if (map[cy][cx] == 'M') { // 보스
            monster = monster_info[{cx, cy}];
            result = ply.boss_fight(monster, { cx, cy });
        }
        else if (map[cy][cx] == '#') { // 벽
            cx -= dx[d_idx];
            cy -= dy[d_idx];
            result = { cx, cy };
            if (spike_pos.count({ cx, cy })) {
                result = ply.spike_trap({ cx, cy });
                monster.name = "SPIKE TRAP";
            }
        }
        else if (spike_pos.count({ cx, cy })) { // 함정
            result = ply.spike_trap({ cx, cy });
            monster.name = "SPIKE TRAP";
        }
        else { // 빈칸
            result = { cx, cy };
        }

        /**
         * restult 관련해서는
         * @see player 클래스 참고
        */
        if (result.first >= 0) { //일반적인 상황
            if (spike_pos.count({ nx, ny })) map[ny][nx] = '^';
            else map[ny][nx] = '.';
            map[result.second][result.first] = '@';
            nx = result.first;
            ny = result.second;
        }
        else if (result.first < 0) { // 보스전, 사망등 게임이 종료되는 조건 
            turn++; // 마지막 턴 마무리
            if (result.first == -2) { // 사망
                if (spike_pos.count({ nx, ny })) map[ny][nx] = '^'; // 죽은 위치가 함정이면
                else map[ny][nx] = '.'; // 죽은 위치가 빈칸이면
                end_message = "YOU HAVE BEEN KILLED BY " + monster.name + "..";
                break;
            }
            else if (result.first == -3) { // 보스전 승리
                if (spike_pos.count({ nx, ny })) map[ny][nx] = '^'; // 보스전 진입전 위치가 스파이크이면
                else map[ny][nx] = '.'; // 보스전 진입전 위치가 빈칸이면
                map[cy][cx] = '@'; // 보스전 승리시 보스 위치에 @ 표시
                end_message = "YOU WIN!";
                break;
            }
        }
        /**
         * ----------------
         * <<디버깅용 주석>>
         * ----------------
        */
        // map_print();
        // ply.print_player_status();
        // cout << "==" << i << ':' << turn << '\n';
        turn++;
    }
    map_print();
    cout << "Passed Turns : " << turn << '\n';
    ply.print_player_status();
    cout << end_message << '\n';
}

int main() {
    input();
    solution();
}