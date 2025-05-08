#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, A;
vector<int> score;

long getScore(const vector<int>& score, long target) {
    long max_score = 0;
    int left = 0, right = score.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target >= score[mid]) {
            max_score = max(max_score, (long)score[mid]);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return max_score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> A;
    score.resize(N);

    long max_val = 0;
    for (int i = 0; i < N; ++i) {
        cin >> score[i];
        max_val = max(max_val, (long)score[i]);
    }

    sort(score.begin(), score.end());

    long left = 1, right = max_val;
    while (left <= right) {
        long mid = (left + right) / 2;
        long sum = 0;

        for (int i = 0; i < M; ++i) {
            sum += getScore(score, mid + sum);
        }

        if (sum >= A) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}
