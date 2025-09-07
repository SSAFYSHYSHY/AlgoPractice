#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    vector<string> dictionary;
    map<string, vector<string>> mp; // ���ĵ� ���� -> ������ �ܾ� ���

    // 1. ���� �Է�
    while (true) {
        string word;
        cin >> word;
        if (word == "XXXXXX") break;
        dictionary.push_back(word);

        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        mp[sorted_word].push_back(word);
    }

    // ���� �ܾ�� ���ĺ� ������ ����
    for (auto& p : mp) {
        sort(p.second.begin(), p.second.end());
    }

    // 2. ���� �ܾ� ó��
    while (true) {
        string scrambled;
        cin >> scrambled;
        if (scrambled == "XXXXXX") break;

        string key = scrambled;
        sort(key.begin(), key.end());

        if (mp.count(key)) {
            // ������ �ܾ� ���
            for (string w : mp[key]) {
                cout << w << "\n";
            }
        }
        else {
            cout << "NOT A VALID WORD\n";
        }

        cout << "******\n"; // ��� �� ǥ��
    }

    return 0;
}
