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
    cin.ignore(); // 개행 문자 제거

    while (t--) {
        unordered_set<string> not_fox;
        vector<string> all_sounds;

        // 전체 녹음된 소리 받기
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            all_sounds.push_back(word);
        }

        // 동물 소리 정보 입력 받기
        while (true) {
            getline(cin, line);
            if (line == "what does the fox say?") break;

            stringstream ss2(line);
            string animal, goes, sound;
            ss2 >> animal >> goes >> sound;
            not_fox.insert(sound);
        }

        // 여우의 소리만 출력
        for (auto& sound : all_sounds) {
            if (not_fox.find(sound) == not_fox.end()) {
                cout << sound << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
