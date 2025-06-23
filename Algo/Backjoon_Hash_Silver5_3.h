#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    vector<string> students;
    unordered_map<string, int> index_map;

    stringstream ss(line);
    string name;
    for (int i = 0; i < n; ++i) {
        ss >> name;
        students.push_back(name);
        index_map[name] = i;
    }

    vector<int> popularity(n, 0);

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        stringstream ss2(line);
        while (ss2 >> name) {
            popularity[index_map[name]]++;
        }
    }

    vector<pair<string, int>> result;
    for (int i = 0; i < n; ++i) {
        result.push_back({ students[i], popularity[i] });
    }

    sort(result.begin(), result.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
        });

    // Ãâ·Â
    for (const auto& p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}