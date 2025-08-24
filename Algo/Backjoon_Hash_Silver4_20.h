#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
unordered_map<string, long long> score;

bool cmp(const pair<string, long long>& a, const pair<string, long long>& b) {
    if (a.second == b.second) return a.first < b.first; // 점수 같으면 알파벳 순
    return a.second > b.second; // 점수 큰 순
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    long long N = (n * (n - 1)) / 2;

    for (long long i = 0; i < N; i++) {
        string a, b;
        long long c, d;
        cin >> a >> b >> c >> d;

        if (c > d) {
            score[a] += 3;
        }
        else if (c < d) {
            score[b] += 3;
        }
        else {
            score[a] += 1;
            score[b] += 1;
        }
    }

    // unordered_map → vector 변환
    vector<pair<string, long long>> v(score.begin(), score.end());

    // 정렬
    sort(v.begin(), v.end(), cmp);

    // 상위 5 출력
    for (long long i = 0; i < (long long)v.size() && i < 5; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}
