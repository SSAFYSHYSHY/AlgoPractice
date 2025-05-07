#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // 아름다운 쌍 저장: pair[a][b] == true 면 (a, b)는 아름다운 쌍
    bool pair[26][26] = { false };

    for (int i = 0; i < k; i++) {
        char a, b;
        cin >> a >> b;
        pair[a - 'a'][b - 'a'] = true;
    }

    // 누적합: 각 문자 c에 대해, 지금까지 등장한 횟수 cnt[c]
    vector<long long> count(26, 0);

    long long result = 0;

    for (char ch : s) {
        int current = ch - 'a';

        // 지금까지 등장한 a 중, (a, current)가 아름다운 쌍인 경우 수만큼 더함
        for (int prev = 0; prev < 26; prev++) {
            if (pair[prev][current]) {
                result += count[prev];
            }
        }

        // 현재 문자 등장 횟수 증가
        count[current]++;
    }

    cout << result << endl;
    return 0;
}
