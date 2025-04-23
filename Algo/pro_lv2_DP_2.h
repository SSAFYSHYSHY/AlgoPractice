#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();

    for (int i = 1; i < len; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;

            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    sum = max(sum, land[i - 1][k]);
                }
            }
            land[i][j] += sum;
        }
    }

    return *max_element(land[len - 1].begin(), land[len - 1].end());
}