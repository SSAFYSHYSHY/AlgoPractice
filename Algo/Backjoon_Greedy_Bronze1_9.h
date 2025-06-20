#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        int n;
        cin >> n;

        vector<int> v(n);
        vector<int> temp(n);

        // 1부터 n까지 초기화 및 lst 입력
        for (int i = 0; i < n; ++i) {
            temp[i] = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        for (int i = 0; i < n; ++i) {
            if (temp[i] == v[i]) {
                temp[i] += 1;
            }

            for (int j = i + 1; j < n; ++j) {
                if (temp[j - 1] >= temp[j]) {
                    temp[j] += (temp[j - 1] - temp[j]) + 1;
                }
            }
        }

        cout << temp[n - 1] << endl;
    }

    return 0;
}
