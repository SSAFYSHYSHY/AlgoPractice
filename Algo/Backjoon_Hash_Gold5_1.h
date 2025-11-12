#pragma once
#include <iostream>
#include <string>
#include <set>

using namespace std;

string arr[1001], str[1001];

int main() {

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> arr[i];
    }


    for (int i = 0; i < c; i++) {
        set<string> s;
        set<string>::iterator iter;

        for (int j = 0; j < r; j++) {
            str[i] += arr[j][i];
        }

        s.insert(str[i]);
    }

    for (int i = 0; i < r; i++) {
        set<string> s;
        set<string>::iterator iter;

        for (int j = 0; j < c; j++) {
            if (str[j].size() != 0) {
                str[j].erase(str[j].begin());

                iter = s.find(str[j]);
                if (iter == s.end()) {
                    s.insert(str[j]);
                }
                else {
                    if (i == 0) {
                        cout << 0;
                        return 0;
                    }
                    cout << i;
                    return 0;
                }
            }

        }
    }
    cout << r - 1;

}