#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

int t;
string line;

int main() {
    cin >> t;
    cin.ignore(); // ���� ���� ����

    while (t--) {
        unordered_set<string> not_fox;
        vector<string> all_sounds;

        // ��ü ������ �Ҹ� �ޱ�
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            all_sounds.push_back(word);
        }

        // ���� �Ҹ� ���� �Է� �ޱ�
        while (true) {
            getline(cin, line);
            if (line == "what does the fox say?") break;

            stringstream ss2(line);
            string animal, goes, sound;
            ss2 >> animal >> goes >> sound;
            not_fox.insert(sound);
        }

        // ������ �Ҹ��� ���
        for (auto& sound : all_sounds) {
            if (not_fox.find(sound) == not_fox.end()) {
                cout << sound << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
