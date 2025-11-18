#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
long long sx;
vector<pair<char, long long>> ops;

unordered_set<long long> arr;
unordered_set<long long> visited;

struct Node {
	long long num;
	vector<int> path;
};

bool InRange(int nx) {
	return 0 <= nx && nx <= 2000000000LL;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		if (i == k) sx = num;

		arr.insert(num);
	}

	ops.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> ops[i].first >> ops[i].second;
	}

	queue<Node> q;
	q.push({ sx, {} });
	visited.insert(sx);

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (arr.count(cur.num) == 0) {
			cout << cur.path.size() << "\n";

			for (int i : cur.path) {
				cout << i << "\n";
			}

			return 0;
		}

		for (int i = 0; i < m; i++) {
			char op = ops[i].first;
			long long v = ops[i].second;
			long long nx;

			if (op == '+') {
				nx = cur.num + v;
			}
			else if (op == '-') {
				nx = cur.num - v;

				if (nx < 0) continue;
			}
			else if (op == '*') {
				nx = cur.num * v;
			}
			else if (op == '/') {
				if (v == 0) continue;

				nx = cur.num / v;
			}

			if (!InRange(nx)) continue;

			if (!visited.count(nx)) {
				visited.insert(nx);
				Node nxt = cur;
				nxt.num = nx;
				nxt.path.push_back(i + 1);
				q.push(nxt);
			}
		}
	}

	cout << -1 << "\n";
	return 0;
}
