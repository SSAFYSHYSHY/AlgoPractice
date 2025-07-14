#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> attack;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    int sum = 0;
    for (int i = 0; i < attacks.size(); i++) {

        //초기 적의 구조에 대해서.
        if (i == 0) {
            int s = 0;
            int e = attacks[i][0];
            int hp = attacks[i][1];

            //연산.
            int num = e - s - 1;
            int mod = num / t;

            sum = health + (mod * y) + (num * x);
            if (sum > health) {
                sum = health;
            }

            //감산.
            sum -= hp;
        }
        //나머지 연산에 대해서.
        else {
            int s = attacks[i - 1][0];
            int e = attacks[i][0];
            int hp = attacks[i][1];

            //연산.
            int num = e - s - 1;
            int mod = num / t;

            sum = sum + (mod * y) + (num * x);
            if (sum > health) {
                sum = health;
            }

            sum -= hp;
        }

        if (sum <= 0) {
            return -1;
        }
    }

    answer = sum;
    return answer;
}