#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int size;
	vector<pair<int, int>> path;
};

vector<Node> v;

struct Node2 {
	int x, y, cnt;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

Node BFS(int x, int y) {
	vector<pair<int, int>> v2;
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		v2.push_back({ cx,cy });

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}

	return { (int)v2.size(), v2 };
}

bool cmp(Node a, Node b) {
	return a.size < b.size;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = (int)(s[j] - '0');
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				Node nodes = BFS(i, j);

				v.push_back(nodes);
			}
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (int t = 0; t < v.size(); t++) {
		vector<pair<int, int>> copy_path = v[t].path;

		for (int i = 0; i < copy_path.size(); i++) {
			int x = copy_path[i].first;
			int y = copy_path[i].second;

			arr[x][y] = t + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}