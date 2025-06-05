#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;

bool cmp(string a, string b) {
    if (a[num] != b[num]) return a[num] < b[num];
    else {
        return a < b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    num = n;

    sort(strings.begin(), strings.end(), cmp);

    return strings;
}