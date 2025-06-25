#pragma once
#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> q;
	int idx = 0, ans = 0;

	int n, m, x;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	while (m--) {
		cin >> x;

		for (int i = 0; i < q.size(); i++) {
			if (q[i] == x) {
				idx = i;
				break;
			}
		}

		if (idx <= q.size() / 2) {
			while (1) {
				if (q.front() == x) {
					q.pop_front();
					break;
				}
				++ans;

				q.push_back(q.front());
				q.pop_front();
			}
		}
		else {
			while (1) {
				if (q.front() == x) {
					q.pop_front();
					break;
				}
				++ans;

				q.push_front(q.back());
				q.pop_back();
			}
		}
	}

	cout << ans;
}