#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int w, h, x, y;
int arr[1001][1001];
bool visited[1001][1001] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> path;

bool InRange(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

void BFS(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		path.push_back({ cx,cy });

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[x][y] == arr[nx][ny]) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}

bool cmp(pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {

	cin >> w >> h >> y >> x;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}

	BFS(x, y, arr[x][y]);

	sort(path.begin(), path.end(), cmp);

	for (int i = 0; i < path.size(); i++) {
		cout << path[i].second << " " << path[i].first << "\n";
	}

}