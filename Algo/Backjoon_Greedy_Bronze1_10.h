#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>

using namespace std;

int countOnes(int num) {
    int cnt = 0;
    while (num) {
        cnt += (num & 1);
        num >>= 1;
    }
    return cnt;
}

int main() {
    int size, a, b;
    cin >> size >> a >> b;

    int limit = 1 << size; // 2^size
    vector<int> aCases, bCases;

    for (int i = 0; i < limit; ++i) {
        int oneCnt = countOnes(i);
        if (oneCnt == a) aCases.push_back(i);
        if (oneCnt == b) bCases.push_back(i);
    }

    int answer = 0;
    for (int x : aCases) {
        for (int y : bCases) {
            answer = max(answer, x ^ y);
        }
    }

    cout << answer << endl;
    return 0;
}
