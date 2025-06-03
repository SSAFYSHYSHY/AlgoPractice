#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    vector<long long> v;

    for (int i = 0; i < s.length(); i++) {
        v.push_back((int)(s[i] - '0'));
    }

    sort(v.begin(), v.end(), cmp);

    string s2;
    for (int i = 0; i < v.size(); i++) {
        s2 += (v[i] + '0');
    }
    answer = stoll(s2);


    return answer;
}