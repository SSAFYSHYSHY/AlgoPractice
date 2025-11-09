#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push({ i ,num });
	}

	vector<int> v(M + 1, 0);
	for (int i = 1; i <= M; i++) {
		cin >> v[i];
	}

	vector<pair<int, int>> v2(M + 1);
	queue<int>q;
	int ans = 0, num;

	for (int i = 0; i < 2 * M; ++i) {
		cin >> num;
		if (num < 0) {
			num *= -1;
			ans += v2[num].second * v[num];
			pq.push(v2[num]);
			if (!q.empty()) {
				num = q.front();
				q.pop();
				v2[num] = pq.top();
				pq.pop();
			}
		}
		else if (num > 0) {
			if (pq.empty()) q.push(num);
			else {
				v2[num] = pq.top();
				pq.pop();
			}
		}
	}
	cout << ans;
}