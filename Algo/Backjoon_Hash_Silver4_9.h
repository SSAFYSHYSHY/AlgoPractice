#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> entered;
    int count = 0;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s == "ENTER") {
            entered.clear();
        }
        else {
            if (entered.find(s) == entered.end()) {
                entered.insert(s);
                count++;
            }
        }
    }

    cout << count << "\n";
    return 0;
}
