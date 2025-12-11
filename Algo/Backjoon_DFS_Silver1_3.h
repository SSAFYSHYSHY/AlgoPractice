#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, string> toWhom;
vector<string> order;
map<string, bool> visited;
map<string, bool> seen;

void findCycle(const string& start) {
    string cur = start;
    seen.clear();
    vector<string> path;

    while (true) {
        path.push_back(cur);
        seen[cur] = true;
        cur = toWhom[cur];

        if (seen[cur]) {
            cout << cur;
            string x = toWhom[cur];
            while (x != cur) {
                cout << " to " << x;
                x = toWhom[x];
            }
            cout << " to " << cur << "." << "\n";

            visited[cur] = true;
            x = toWhom[cur];
            while (x != cur) {
                visited[x] = true;
                x = toWhom[x];
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int party = 1;
    while (true) {
        toWhom.clear();
        visited.clear();
        order.clear();

        string a, b;
        if (!(cin >> a)) return 0;
        if (a == "#") return 0;
        cin >> b;

        toWhom[a] = b;
        order.push_back(a);

        while (true) {
            cin >> a;
            if (a == "#") break;
            cin >> b;
            if (toWhom.count(a) == 0)
                order.push_back(a);
            toWhom[a] = b;
        }

        cout << "Party number " << party++ << "\n";

        for (auto& name : order) {
            if (!visited[name])
                findCycle(name);
        }
        cout << "\n";
    }
    return 0;
}
