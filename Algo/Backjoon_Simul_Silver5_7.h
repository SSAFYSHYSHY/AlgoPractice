#pragma once
#include <iostream>

using namespace std;

int N, K;
int gold[1001];
int silver[1001];
int bronze[1001];
int ans = 0;

int main() {

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int idx;
        cin >> idx;
        cin >> gold[idx] >> silver[idx] >> bronze[idx];
    }

    for (int i = 1; i <= N; i++) {
        if (gold[i] > gold[K]) {
            ans++;
        }
        else if (gold[i] == gold[K]) {
            if (silver[i] > silver[K]) {
                ans++;
            }
            else if (silver[i] == silver[K]) {
                if (bronze[i] > bronze[K]) {
                    ans++;
                }
            }
        }
    }

    cout << ans + 1;
}
