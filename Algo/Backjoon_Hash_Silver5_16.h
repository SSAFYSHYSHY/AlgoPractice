#pragma once
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> used;
    int num = 0;
    used.insert(num);

    for (int i = 1; i <= n; i++) {
        int new_num = num - i;
        if (new_num < 0 || used.find(new_num) != used.end()) {
            new_num = num + i;
        }
        used.insert(new_num);
        num = new_num;
    }

    cout << num << "\n"; // 마지막 값이 A_n
    return 0;
}
