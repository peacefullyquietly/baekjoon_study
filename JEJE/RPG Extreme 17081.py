# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
class Box:
    def __init__(self, type :str, value :int|str):
        self.box_type = type
        self.isOpen = False
        self.value = value

    def pop(self):
        self.isOpen = True
        return self.value

    def __str__(self):
        if self.isOpen:
            return '.'
        else:
            return 'B'

class Info:
    name = 'Press any key to continue.'
    pos = {'x': 0, 'y': 0}
    hp = 0
    df = 0
    atk = 0
    exp = 0
    max_hp = 0
    level = 1

class Monster(Info):
    isBoss = False
    def __init__(self, x :int, y :int, name :str, atk :int, df :int, max_hp :int, exp :int):
        self.pos['x'] = x
        self.pos['y'] = y
        self.name = name
        self.max_hp = self.hp = max_hp
        self.df = df
        self.atk = atk
        self.exp = exp

    def __rshift__(self, other) -> int:
        self.hp -= max(1, other.atk - self.df)
        return self.hp <= 0

    def __lshift__(self, other) -> int:
        other.hp -= max(1, self.atk - other.df)
        return other.hp <= 0

    def __str__(self) -> str:
        if self.hp <= 0:
            if self.isBoss:
                return 'M'
            else:
                return '&'
        else:
            return '.'

class Spike(Monster):
    def __init__(self, x :int, y :int):
        super().__init__(x, y, 'SPIKE TRAP', 5, 1e9, 1e9, 1e9)

    def __lshift__(self, other) -> int:
        if 'DX' in other.items:
            self.atk = 1
        else:
            self.atk = 5
        other.hp -= self.atk
    
    def __str__(self) -> str:
        return '^'
    
class Player(Info):
    items = []
    born_pos = {'x': 0, 'y': 0}
    armor = 0

    def __init__(self, x :int, y :int):
        self.pos['x'] = self.born_pos['x'] = x
        self.pos['y'] = self.born_pos['y'] = y
        self.name = 'Press any key to continue.'
        self.hp = self.max_hp = 20 
        self.df = 2
        self.atk = 2
    
    def __str__(self) -> str:
        if self.hp <= 0:
            return '.'
        else:
            return '@'
        
    def print_player_status(self):
        print("LV:", self.level)
        print("HP:", self.hp if self.hp >= 0 else 0, "/", self.max_hp)
        print("ATT:", self.atk + self.weapon)
        print("DEF:", self.df + self.armor)
        print("EXP:", self.exp, "/", 5 * self.level)

if __name__ == "__main__":
    import sys
    board = []

    n, m = list(map(int, sys.stdin.readline().split()))

    boss_pos = {'x': 0, 'y': 0}
    _player_pos = {'x': 0, 'y': 0}
    monster_cnt = 0
    box_cnt = 0

    for i in range(n):
        board[-1].append(list(map(int, sys.stdin.readline().split())))
        for j, val in enumerate(board[-1]):
            if val == '^':
                val = Spike(j, i)
            elif val == 'M':
                boss_pos['x'] = j
                boss_pos['y'] = i
                monster_cnt += 1
            elif val == '@':
                _player_pos['x'] = j
                _player_pos['y'] = i
                player = val = Player(j, i)
            elif val == '&':
                monster_cnt += 1
            elif val == 'B':
                box_cnt += 1
            
    move = list(map(str, list(sys.stdin.readline().strip())))

    for i in range(monster_cnt):
        y, x, name, atk, df, hp, exp = list(sys.stdin.readline().split())
        y = int(y)
        x = int(x)
        atk = int(atk)
        df = int(df)
        hp = int(hp)
        exp = int(exp)
        board[y][x] = Monster(x, y, name, atk, df, hp, exp)
        if x == boss_pos['x'] and y == boss_pos['y']:
            board[y][x].isBoss = True

    for i in range(box_cnt):
        y, x, box_type, value = list(sys.stdin.readline().split())
        y = int(y)
        x = int(x)
        if box_type != 'O':
            value = int(value)
        else:
            value = str(value)
        board[y][x] = Box(box_type, value)

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    for i in move:
        if i == 'U':
            mv = 1
        elif i == 'D':
            mv = 0
        elif i == 'R':
            mv = 2
        elif i == 'L':
            mv = 3
        
        if player.hp <= 0:
            break