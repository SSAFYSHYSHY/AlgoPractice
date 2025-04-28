#pragma once
#include <bits/stdc++.h>

using namespace std;
vector<int> v;

bool isCheck(int num) {
    if (num % 2 == 0) return true;
    else return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; int K; cin >> N >> K;
    v.emplace_back(0);
    for (int i = 0; i < N; ++i) {
        int num; cin >> num;
        v.emplace_back(num);
    }
    int maxLen = 0;
    for (int start = 1; start <= N; ++start) {
        int end = start + 1;
        int oddcnt = 0; // È¦¼ö °³¼ö
        int evencnt = 0;
        if (!isCheck(v[start])) oddcnt += 1;
        else evencnt += 1;

        while (end <= N) {
            if (!isCheck(v[end])) {
                oddcnt += 1;
                if (oddcnt > K) {
                    oddcnt -= 1;
                    break;
                }
            }
            else {
                evencnt += 1;
            }
            end += 1;
        }

        maxLen = max(maxLen, evencnt);
    }
    cout << maxLen;
    return 0;
}