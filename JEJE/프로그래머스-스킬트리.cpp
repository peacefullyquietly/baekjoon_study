// https://programmers.co.kr/learn/courses/30/lessons/49993?language=cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, count = 0;
    map<char, int> m;
    for (int i = 0; i < skill.size(); i++)
    {
        m[skill[i]] = i + 1;
    }
    for (auto &i : skill_trees) {
        int cnt = 1;
        for (char &j : i)
        {
            int soon = m[j];
            if (soon == cnt) cnt += 1;
            else if (soon > cnt) { cnt = 0; break; }
            else if (cnt == skill.size() && 1 != skill.size()) break;
        }
        if (cnt > 0) answer += 1;
    }
    return answer;
}