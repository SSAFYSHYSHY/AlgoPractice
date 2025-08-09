#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s;
int n, m;
int arr[1000001];
int prefix[1000001];
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> s;

    int totalDays = n + m - 1;

    arr[0] = 0;
    for (int i = 0; i < totalDays; i++) {
        if (s[i] == 'S') {
            arr[i + 1] = 0;
        }
        else {
            arr[i + 1] = 1;
        }
    }

    prefix[0] = 0;
    for (int i = 1; i <= totalDays; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int num = prefix[i + m - 1] - prefix[i - 1];
        v.push_back({ i, num });
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[0].first;
}
