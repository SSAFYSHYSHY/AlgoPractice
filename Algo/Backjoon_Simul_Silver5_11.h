#pragma once
#include <iostream>
using namespace std;

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s && s != "end") {
        bool hasVowel = false;
        int v = 0, c = 0;
        bool ok = true;

        for (int i = 0; i < s.size(); i++) {
            if (i && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
                ok = false;
                break;
            }

            if (vowel(s[i])) {
                hasVowel = true;
                v++;
                c = 0;
            }
            else {
                c++;
                v = 0;
            }

            if (v == 3 || c == 3) {
                ok = false;
                break;
            }
        }

        if (!hasVowel) ok = false;

        cout << "<" << s << "> is "
            << (ok ? "acceptable." : "not acceptable.") << '\n';
    }
}