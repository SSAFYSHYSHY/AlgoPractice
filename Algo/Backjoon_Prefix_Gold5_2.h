#pragma once
#include <iostream>

using namespace std;

int N, M, H[100000];
int a, b, k;
int arr[100001], sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> H[i];

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> k;
        arr[a - 1] += k;
        arr[b] -= k;
    }

    for (int i = 0; i < N; i++) {
        sum += arr[i];
        H[i] += sum;
        cout << H[i] << ' ';
    }

    return 0;
}