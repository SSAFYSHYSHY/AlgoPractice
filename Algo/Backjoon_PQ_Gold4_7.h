#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int val, idx;
    bool operator>(const Node& other) const {
        if (val != other.val) return val > other.val;
        return idx > other.idx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> rec(n + m + 1);

    priority_queue<Node, vector<Node>, greater<Node>> NS, MS;

    for (int i = 1; i <= n + m; i++) {
        cin >> rec[i];
        if (i <= n)
            NS.push({ rec[i], i });
        else
            MS.push({ rec[i], i });
    }

    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;

        if (op == 'U') {
            int x, y;
            cin >> x >> y;

            rec[x] = y;
            // 새 값 push (lazy update)
            if (x <= n) NS.push({ y, x });
            else MS.push({ y, x });
        }
        else {
            // 최신 값이 아닐 경우 pop
            while (NS.top().val != rec[NS.top().idx]) NS.pop();
            while (MS.top().val != rec[MS.top().idx]) MS.pop();

            cout << NS.top().idx << " " << MS.top().idx << "\n";
        }
    }

    return 0;
}