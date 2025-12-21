#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> cutX = { 0, M };
    vector<int> cutY = { 0, N };

    for (int i = 0; i < K; i++) {
        int d, p;
        cin >> d >> p;
        if (d == 0) cutX.push_back(p);
        else cutY.push_back(p);
    }

    sort(cutX.begin(), cutX.end());
    sort(cutY.begin(), cutY.end());

    int maxW = 0, maxH = 0;

    for (int i = 1; i < cutX.size(); i++)
        maxW = max(maxW, cutX[i] - cutX[i - 1]);

    for (int i = 1; i < cutY.size(); i++)
        maxH = max(maxH, cutY[i] - cutY[i - 1]);

    cout << maxW * maxH << '\n';
    return 0;
}