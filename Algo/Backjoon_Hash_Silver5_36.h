#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    unordered_set<string> dictionary; // »çÀü
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    cin >> m;

    for (int email_idx = 1; email_idx <= m; email_idx++) {
        vector<string> unknown_words;
        while (true) {
            string word;
            cin >> word;
            if (word == "-1") break;

            if (dictionary.find(word) == dictionary.end()) {
                unknown_words.push_back(word);
            }
        }

        if (unknown_words.empty()) {
            cout << "Email " << email_idx << " is spelled correctly.\n";
        }
        else {
            cout << "Email " << email_idx << " is not spelled correctly.\n";
            for (auto& w : unknown_words) {
                cout << w << "\n";
            }
        }
    }

    cout << "End of Output\n";

    return 0;
}
