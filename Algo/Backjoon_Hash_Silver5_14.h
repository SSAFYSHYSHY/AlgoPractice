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
    sliced.swap(tmp); // ���� ��ü
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K, S;
    char c;
    string s;

    unordered_set<char> slicechar = { ' ' }; // �⺻ ������: ����
    unordered_set<char> mergechar;

    // N���� ������ �߰�
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c;
        slicechar.insert(c);
    }

    // M���� ������ �߰�
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> c;
        slicechar.insert(c);
    }

    // K���� ������ �Է� �� slicechar���� ����
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> c;
        mergechar.insert(c);
    }
    for (char ch : mergechar) {
        slicechar.erase(ch);
    }

    // ���ڿ� �Է�
    cin >> S;
    cin.ignore();
    getline(cin, s);

    // �����̽� ó��
    vector<string> sliced;
    sliced.push_back(s);
    for (char ch : slicechar) {
        slice(sliced, ch);
    }

    // ���
    for (string& part : sliced) {
        if (!part.empty()) cout << part << "\n";
    }
    return 0;
}
