#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
double maxi = 0, mini = 0;

int main() {
    cout << fixed;
    cout.precision(4);

    cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    int remain = n - m;
    double sum1 = sum;

    // 최소 평점: 나머지가 모두 -3일 때
    sum1 += -3 * remain;

    // 최대 평점: 나머지가 모두 +3일 때
    sum += 3 * remain;

    mini = sum1 / n;
    maxi = static_cast<double>(sum) / n;

    cout << mini << " " << maxi;
}
