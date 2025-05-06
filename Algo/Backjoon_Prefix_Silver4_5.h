#pragma once
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    long long even = 1;  // prefix sum이 0일 때 (짝수), 공집합 포함
    long long odd = 0;
    int prefix_sum = 0;
    long long result = 0;

    for (int i = 0; i < N; i++) {
        prefix_sum += b[i];
        if (prefix_sum % 2 == 0) {
            result += odd;
            even++;
        }
        else {
            result += even;
            odd++;
        }
    }

    cout << result << endl;
    return 0;
}
