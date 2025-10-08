#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int toMin(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string toStr(int x) {
    int h = x / 60, m = x % 60;
    string hh = (h < 10 ? "0" : "") + to_string(h);
    string mm = (m < 10 ? "0" : "") + to_string(m);
    return hh + ":" + mm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crew;
    for (auto& s : timetable) crew.push_back(toMin(s));
    sort(crew.begin(), crew.end());

    int bus = 540; // 09:00
    int idx = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (idx < crew.size() && crew[idx] <= bus && cnt < m) {
            idx++;
            cnt++;
        }

        if (i == n - 1) { // ¸¶Áö¸· ¼ÅÆ²
            if (cnt < m) return toStr(bus);
            else return toStr(crew[idx - 1] - 1);
        }

        bus += t;
    }

    return "";
}
