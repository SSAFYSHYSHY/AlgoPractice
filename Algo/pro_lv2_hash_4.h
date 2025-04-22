#pragma once
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> map;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (int i = 0; i < phone_book.size(); i++) {
        map.insert(phone_book[i]);
    }

    for (int i = 0; i < phone_book.size(); i++) {
        string temp = "";

        for (int j = 0; j < phone_book[i].size() - 1; j++) {
            temp += phone_book[i][j];

            if (map.find(temp) != map.end()) {
                return false;
            }
        }
    }

    return answer;
}