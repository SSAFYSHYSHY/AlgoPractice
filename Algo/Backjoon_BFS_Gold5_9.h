#pragma once
#include<iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n;
bool visited[10001] = { false, };
vector<int> v[10001];
vector<pair<int, int>> sector;

int Find() {
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 1) {
			return i;
		}
	}
}

void BFS(int sx) {
	queue<int> q;
	q.push(sx);
	visited[sx] = true;

	while (!q.empty()) {
		int cx = q.front();
		q.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i];
			int ssize = v[nx].size();

			if (visited[nx]) continue;

			if (ssize >= 3) {
				sector.push_back({ nx,ssize });
			}

			q.push(nx);
			visited[nx] = true;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n + 3; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	int tail = Find();
	sector.push_back({ tail,1 });

	BFS(tail);

	reverse(sector.begin(), sector.end());

	vector<int> ans;
	ans.push_back(sector[0].first);

	int l = 0, mid = 0, r = 0;
	bool flag = false;
	for (int i = 1; i <= 3; i++) {
		if (sector[i].second == 4) {
			mid = i;
		}
		else if (!flag && sector[i].second == 3) {
			l = i;
			flag = true;
		}
		else if (flag && sector[i].second == 3) {
			r = i;
		}
	}

	if (l < r) {
		swap(l, r);
	}
	ans.push_back(sector[l].first);
	ans.push_back(sector[mid].first);
	ans.push_back(sector[r].first);
	ans.push_back(sector[4].first);
	ans.push_back(sector[5].first);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}