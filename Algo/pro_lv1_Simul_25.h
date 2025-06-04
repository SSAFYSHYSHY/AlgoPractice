#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
    return a > b;
}

string solution(string s) {
    string answer = "";
    vector<char> v;

    for (int i = 0; i < s.length(); i++) {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }

    return answer;
}