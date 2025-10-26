#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> v[100001];
bool visited[100001] = { false, };

int BFS(int start, int endi) {
	visited[start] = true;
	queue<pair<int, int>> q;
	q.push({ start, 0 });

	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (curr == endi) {
			return dist - 1;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
	}

	while (1) {
		memset(visited, false, sizeof(visited));

		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)break;

		int ans = BFS(a, b);
		if (ans == -1) {
			cout << "No\n";
		}
		else {
			cout << "Yes " << ans << "\n";
		}
	}

}