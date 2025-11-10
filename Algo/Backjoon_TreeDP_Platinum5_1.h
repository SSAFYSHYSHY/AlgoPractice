#pragma once
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> v[101];
int node[101];
bool visited[101] = { false, };

bool DFS(int starti) {
	for (int i = 0; i < v[starti].size(); i++) {
		int next = v[starti][i];

		if (visited[next]) {
			continue;
		}

		visited[next] = true;

		if (node[next] == 0 || DFS(node[next])) {
			node[next] = starti;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (DFS(i)) {
			cnt++;
		}
	}

	cout << cnt;

}