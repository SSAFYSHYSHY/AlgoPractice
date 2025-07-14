#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> attack;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0, e = 0, hp = health;

    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    for (int i = 0; i < attacks.size(); i++) {
        int s = attacks[i][0];
        int damage = attacks[i][1];

        int num = s - e - 1;
        if (num > 0) {
            int mod = (num / t) * y;
            hp += num * x + mod;
            if (hp > health) {
                hp = health;
            }
        }

        hp -= damage;

        if (hp <= 0) {
            return -1;
        }

        e = s;
    }

    answer = hp;
    return answer;
}