#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int n, ans;
unordered_map<string, vector<string>> adj;
unordered_set<string> visited;

void Calc(string s) {
    string group;
    int pos = s.find(':');
    group = s.substr(0, pos);

    string rest = s.substr(pos + 1);
    if (rest.back() == '.') rest.pop_back();

    stringstream ss(rest);
    string member;
    while (getline(ss, member, ',')) {
        adj[group].push_back(member);
    }
}

void BFS(string start) {
    queue<string> q;
    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (adj.find(cur) == adj.end()) {
            ans++;
            continue;
        }

        for (auto& next : adj[cur]) {
            if (!visited.count(next)) {
                visited.insert(next);
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n;
        if (n == 0) break;

        adj.clear();
        visited.clear();
        ans = 0;

        vector<string> order; // ù ��° �׷� ����
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            order.push_back(s.substr(0, s.find(':'))); // �׷� �̸� ����
            Calc(s);
        }

        string start = order[0]; // ù ��° �Էµ� �׷�
        BFS(start);

        cout << ans << "\n";
    }
    return 0;
}#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int n, ans;
unordered_map<string, vector<string>> adj;
unordered_set<string> visited;

void Calc(string s) {
    string group;
    int pos = s.find(':');
    group = s.substr(0, pos);

    string rest = s.substr(pos + 1);
    if (rest.back() == '.') rest.pop_back();

    stringstream ss(rest);
    string member;
    while (getline(ss, member, ',')) {
        adj[group].push_back(member);
    }
}

void BFS(string start) {
    queue<string> q;
    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (adj.find(cur) == adj.end()) {
            ans++;
            continue;
        }

        for (auto& next : adj[cur]) {
            if (!visited.count(next)) {
                visited.insert(next);
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n;
        if (n == 0) break;

        adj.clear();
        visited.clear();
        ans = 0;

        vector<string> order; // ù ��° �׷� ����
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            order.push_back(s.substr(0, s.find(':'))); // �׷� �̸� ����
            Calc(s);
        }

        string start = order[0]; // ù ��° �Էµ� �׷�
        BFS(start);

        cout << ans << "\n";
    }
    return 0;
}