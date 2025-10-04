#pragma once
//https://school.programmers.co.kr/learn/courses/30/lessons/150370
#include <string>
#include <vector>
#include <map>
using namespace std;

int toDays(string s) {
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));
    return y * 12 * 28 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termMap;

    // 약관 종류별 개월 수 기록
    for (string t : terms) {
        char c = t[0];
        int m = stoi(t.substr(2));
        termMap[c] = m;
    }

    int todayVal = toDays(today);

    for (int i = 0; i < privacies.size(); i++) {
        string date = privacies[i].substr(0, 10);
        char type = privacies[i].back();

        int start = toDays(date);
        int expire = start + termMap[type] * 28 - 1; // -1일

        if (expire < todayVal) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
