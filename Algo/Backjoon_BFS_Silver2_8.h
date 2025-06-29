#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];
vector<int> v[101];
bool visited[101];
int n, m;

void BFS(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int size = q.size();
		vector<int> level;

		for (int i = 0; i < size; i++) {
			int cx = q.front(); q.pop();
			level.push_back(cx);

			for (int j = 0; j < v[cx].size(); j++) {
				int next = v[cx][j];
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}

		// 오름차순 정렬 후 출력
		sort(level.begin(), level.end());
		for (int x : level) {
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				v[i].push_back(j);
			}
		}
	}

	BFS(m);
}
