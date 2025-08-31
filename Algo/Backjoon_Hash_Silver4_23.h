#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<string> v;

bool check(string a, string b) {
    if (a.length() != b.length()) return false;

    for (int i = 0; i < b.length(); i++) {
        string temp = b.substr(i, b.length() - i) + b.substr(0, i);
        if (a == temp) return true;
    }

    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s; v.push_back(s);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (i == j) continue;
            // 같다면, 앞의 것과 똑같이 바꿀 것
            if (check(v[i], v[j])) {
                v[j] = v[i];
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size();

    return 0;
}