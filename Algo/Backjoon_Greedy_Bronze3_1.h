#pragma once
#include <iostream>
#include <string>

using namespace std;


int main() {
    int h;
    cin >> h;

    string result = "";

    if (h == 0) {
        cout << "1";
        return 0;
    }
    else if (h == 1) {
        cout << "0";
        return 0;
    }
    else {
        int n = h / 2;
        int m = h % 2;

        if (m == 1) cout << "4";

        for (int i = 0; i < n; i++) {
            cout << "8";
        }
    }
    return 0;
}