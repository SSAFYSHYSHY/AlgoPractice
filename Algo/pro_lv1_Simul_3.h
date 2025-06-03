#pragma once
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    vector<int> v;
    string s = to_string(n);

    for (int i = 0; i < s.length(); i++) {
        v.push_back((int)(s[i] - '0'));
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        answer.push_back(v[i]);
    }

    return answer;
}