#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int t;
bool visited[100001] = { false, };
vector<int> v[100001];

int BFS(int starti) {
	memset(visited, false, sizeof(visited));

	queue<int> q;
	int cnt = 1;
	q.push(starti);
	visited[starti] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		memset(visited, false, sizeof(visited));

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;

			v[a].push_back(i);
		}

		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			int num = BFS(i);
			ans.push_back(num);
		}

		cout << "Case #" << tc << ":\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}


		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
	}

}

