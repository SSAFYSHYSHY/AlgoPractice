#pragma once
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    map<string, int> map_;
    string S;
    double total = 0;
    while (getline(cin, S)) {
        stringstream ss(S);
        while (ss >> S) {
            map_[S]++;
            total += 1;
        }
    }

    vector<string> work = { "Re","Pt","Cc","Ea","Tb","Cm","Ex" };
    for (int i = 0; i < work.size(); i++) {
        string s = work[i];
        if (map_.find(s) != map_.end()) {
            cout << s << ' ' << map_[s] << ' ';
            cout << fixed << setprecision(2) << map_[s] / total;
            cout << '\n';
        }
        else {
            cout << s << ' ' << 0 << ' ';
            cout << "0.00";
            cout << '\n';
        }
    }
    cout << "Total " << (int)total << " 1.00";
    return 0;
}