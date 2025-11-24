#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string normalize(string w) {
    if (w.length() > 3)
        sort(w.begin() + 1, w.end() - 1);
    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N;

    vector<string> dictionary;
    dictionary.reserve(N);

    // 사전 단어 입력
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        dictionary.push_back(normalize(word));
    }

    cin >> T;
    cin.ignore();

    while (T--) {
        string sentence;
        getline(cin, sentence);

        vector<string> words;
        string temp;

        // 문장 단어 분리
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(normalize(temp));
                temp.clear();
            }
            else {
                temp += c;
            }
        }
        if (!temp.empty())
            words.push_back(normalize(temp));

        // 사전에 일치하는 개수 곱하기
        long long result = 1;
        for (auto& w : words) {
            int cnt = 0;
            for (auto& d : dictionary) {
                if (w == d) cnt++;
            }
            result *= cnt;
        }

        cout << result << "\n";
    }

    return 0;
}
