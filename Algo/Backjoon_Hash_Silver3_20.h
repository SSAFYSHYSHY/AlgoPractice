#pragma once
#include <bits/stdc++.h>
using namespace std;

map<string, string> wordCode;
string hufCode;
array<string, (int)(2e6)> wordTree;

void input() {
    int n;

    cin >> n;
    string word, code;

    for (int i = 0; i < n; i++) {
        cin >> word >> code;
        wordCode.insert({ word, code }); // 알파벳, 코드 저장
    }

    cin >> hufCode;
}

void setTree() {
    wordTree.fill("-");
    int idx;

    for (auto iter = wordCode.begin(); iter != wordCode.end(); iter++) {
        idx = 1;
        for (auto x : iter->second) {
            if (x == '0') idx *= 2;
            else idx = idx * 2 + 1;
        }
        wordTree[idx] = iter->first;
    }
}

void sol() {
    setTree();

    string answer;
    int idx = 1;

    for (int i = 0; i < hufCode.length(); i++) {
        if (hufCode[i] == '0') idx *= 2;
        else idx = idx * 2 + 1;

        if (wordTree[idx] != "-") {
            answer += wordTree[idx];
            idx = 1;
        }
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}