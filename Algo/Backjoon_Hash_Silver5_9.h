#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>   // stringstream
using namespace std;

int n, t;
unordered_map<string, int> dict;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        string word;
        int val;
        cin >> word >> val;
        dict[word] = val;
    }

    // 남은 개행 제거
    cin.ignore();

    for (int i = 0; i < t; i++) {
        long long ans = 0;
        string line;

        while (true) {
            getline(cin, line);
            if (line == ".") break;

            stringstream ss(line);
            string word;
            while (ss >> word) {
                if (dict.count(word)) ans += dict[word];
            }
        }
        cout << ans << "\n";
    }
}
