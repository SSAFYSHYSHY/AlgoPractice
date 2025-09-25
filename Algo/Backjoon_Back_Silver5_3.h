#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int N;

string X[7][2];
string s[8] = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
string tmp;

bool chk() {
    for (int i = 0; i < N; i++) {
        bool tmp = 0;
        for (int k = 0; k < 7; k++) {
            if (X[i][0] == s[k] && X[i][1] == s[k + 1]) tmp = 1;
            else if (X[i][0] == s[k + 1] && X[i][1] == s[k]) tmp = 1;
        }
        if (!tmp) return 0;
    }
    return 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> X[i][0] >> tmp >> tmp >> tmp >> tmp >> X[i][1];

    sort(s, s + 8);

    while (!chk()) next_permutation(s, s + 8);

    for (int i = 0; i < 8; i++) cout << s[i] << '\n';
}