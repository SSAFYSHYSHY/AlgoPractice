#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long m, n, s;
bool visited[1000001] = { false, };
vector<pair<long long, long long>> v;

long long BFS() {
	memset(visited, false, sizeof(visited));
	queue<pair<long long, long long>> q;

	q.push({ s,0 });
	visited[s] = true;

	while (!q.empty()) {
		long long now = q.front().first;
		long long cnt = q.front().second;
		q.pop();

		if (now == 0) {
			return cnt;
		}

		for (long long i = 0; i < v.size(); i++) {
			long long next = (now * v[i].first + v[i].second) % m;

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin >> m >> n >> s;

	for (long long i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	cout << BFS() << "\n";

}
