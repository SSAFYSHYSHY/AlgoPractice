#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    vector<string> dictionary;
    map<string, vector<string>> mp; // 정렬된 문자 -> 가능한 단어 목록

    // 1. 사전 입력
    while (true) {
        string word;
        cin >> word;
        if (word == "XXXXXX") break;
        dictionary.push_back(word);

        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        mp[sorted_word].push_back(word);
    }

    // 사전 단어들 알파벳 순으로 정렬
    for (auto& p : mp) {
        sort(p.second.begin(), p.second.end());
    }

    // 2. 섞인 단어 처리
    while (true) {
        string scrambled;
        cin >> scrambled;
        if (scrambled == "XXXXXX") break;

        string key = scrambled;
        sort(key.begin(), key.end());

        if (mp.count(key)) {
            // 가능한 단어 출력
            for (string w : mp[key]) {
                cout << w << "\n";
            }
        }
        else {
            cout << "NOT A VALID WORD\n";
        }

        cout << "******\n"; // 목록 끝 표시
    }

    return 0;
}
