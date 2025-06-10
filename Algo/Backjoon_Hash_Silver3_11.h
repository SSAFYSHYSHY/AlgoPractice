#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (s == "*") break;

        bool surprising = true;

        for (int d = 0; d < s.length() - 1; d++) {
            unordered_set<string> pairs;
            bool duplicate = false;

            for (int i = 0; i + d + 1 < s.length(); i++) {
                string pair = "";
                pair += s[i];
                pair += s[i + d + 1];

                if (pairs.count(pair)) {
                    duplicate = true;
                    break;
                }

                pairs.insert(pair);
            }

            if (duplicate) {
                surprising = false;
                break;
            }
        }

        if (surprising) {
            cout << s << " is surprising." << endl;
        }
        else {
            cout << s << " is NOT surprising." << endl;
        }
    }

    return 0;
}
