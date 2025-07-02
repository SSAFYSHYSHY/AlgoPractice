#pragma once
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int k, n;
long long ans = 0, cnt = 1;

int dx[] = { -1,1 };
queue<int> q;
set<int> s;

long long BFS() {

	while (!q.empty()) {
		int len = q.size();

		for (int i = 0; i < len; i++) {
			int curr = q.front();
			q.pop();

			for (int j = 0; j < 2; j++) {
				int nx = curr + dx[j];

				if (!s.count(nx)) {
					s.insert(nx);
					q.push(nx);
					ans += cnt;

					if (!--k) {
						return ans;
					}
				}
			}
		}

		cnt++;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		q.push(x);
		s.insert(x);
	}

	cout << BFS();
}