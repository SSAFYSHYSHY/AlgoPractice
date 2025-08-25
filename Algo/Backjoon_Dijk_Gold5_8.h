#pragma once
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << 101 << "\n";

    for (int i = 0; i < 101; ++i) {
        cout << 0 << "\n";
    }
    cout << 1 << "\n"
        << 0 << " " << 1;
    return 0;
}