#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
long long m;

struct Node {
	int x;
	long long c;
};

vector<Node> v;

bool Calc(long long num) {
	priority_queue<int, vector<int>, greater<int>> pq;
	long long sum = 0;

	for (auto& b : v) {
		if (b.c > num) continue;
		pq.push(b.x);
		sum += b.x;

		if ((int)pq.size() > n) {
			sum -= pq.top();
			pq.pop();
		}
	}

	return (pq.size() == n && sum >= m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	v.resize(k);
	long long maxc = 0;

	for (int i = 0; i < k; i++) {
		cin >> v[i].x >> v[i].c;

		maxc = max(maxc, v[i].c);
	}

	long long l = 1, r = maxc, ans = -1;

	while (l <= r) {
		long long mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;

}
