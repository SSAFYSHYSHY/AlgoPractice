#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void slice(vector<string>& sliced, char c) {
    vector<string> tmp;
    string t;
    for (int i = 0; i < (int)sliced.size(); i++) {
        stringstream ss(sliced[i]);
        while (getline(ss, t, c)) {
            tmp.push_back(t);
        }
    }
    sliced.swap(tmp); // 벡터 교체
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K, S;
    char c;
    string s;

    unordered_set<char> slicechar = { ' ' }; // 기본 구분자: 공백
    unordered_set<char> mergechar;

    // N개의 구분자 추가
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c;
        slicechar.insert(c);
    }

    // M개의 구분자 추가
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> c;
        slicechar.insert(c);
    }

    // K개의 병합자 입력 → slicechar에서 제거
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> c;
        mergechar.insert(c);
    }
    for (char ch : mergechar) {
        slicechar.erase(ch);
    }

    // 문자열 입력
    cin >> S;
    cin.ignore();
    getline(cin, s);

    // 슬라이스 처리
    vector<string> sliced;
    sliced.push_back(s);
    for (char ch : slicechar) {
        slice(sliced, ch);
    }

    // 출력
    for (string& part : sliced) {
        if (!part.empty()) cout << part << "\n";
    }
    return 0;
}
