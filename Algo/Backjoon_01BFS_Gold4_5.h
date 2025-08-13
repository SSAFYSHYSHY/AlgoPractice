#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
char arr[1001][1001];
int dist[1001][1001];
unordered_map<char, int> map;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int ans[26];

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
			dist[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < 26; i++) {
		ans[i] = INT_MAX;
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

struct Node {
	int cost, x, y;
};

deque<Node> dq;

void BFS() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'W') {
				dist[i][j] = 0;
				dq.push_front({ 0,i,j });
			}
		}
	}

	while (!dq.empty()) {
		int ccost = dq.front().cost;
		int cx = dq.front().x;
		int cy = dq.front().y;
		dq.pop_front();

		char curr = arr[cx][cy];

		if (curr != 'W') {
			if (!map.count(curr) || map[curr] > ccost) {
				map[curr] = ccost;
			}
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;

			int cost = (arr[nx][ny] == curr ? 0 : 1);

			if (dist[nx][ny] > dist[cx][cy] + cost) {
				dist[nx][ny] = dist[cx][cy] + cost;

				if (cost == 0) {
					dq.push_front({ dist[nx][ny] , nx,ny });
				}
				else {
					dq.push_back({ dist[nx][ny] , nx, ny });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	BFS();

	vector<pair<char, int>> ans;
	for (auto& p : map) {
		ans.push_back({ p.first, max(0, p.second - 1) });
	}
	sort(ans.begin(), ans.end());

	for (auto& p : ans) {
		cout << p.first << " " << p.second << "\n";
	}
}