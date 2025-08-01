#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, r, g, ans = 0;
int arr[51][51];
int temp[51][51];
int dist[51][51];
int color[51][51];
bool back_visited[51][51] = { false, };

vector<pair<int, int>> v;
vector<pair<pair<int, int>, int>> back_v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Input() {
	cin >> n >> m >> r >> g;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
}

struct Node {
	//좌표, 현 시간(dist 기록), r,g 인지 num 판별.
	int x, y, curr, num;
};

int BFS() {
	memcpy(temp, arr, sizeof(arr));
	memset(dist, -1, sizeof(dist));
	int cnt = 0;
	int color[51][51] = { 0, };
	bool visited[51][51] = { false, };

	queue<Node> q;

	for (int i = 0; i < back_v.size(); i++) {
		q.push({ back_v[i].first.first , back_v[i].first.second, 0 , back_v[i].second });
		visited[back_v[i].first.first][back_v[i].first.second] = true;
		dist[back_v[i].first.first][back_v[i].first.second] = 0;
	}

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cur_time = q.front().curr;
		int cur_num = q.front().num;
		q.pop();

		if (color[cx][cy] == 3) continue;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			//벽이 아니고, 물이 면 다음 칸으로.
			if (!InRange(nx, ny)) continue;
			if (temp[nx][ny] == 0) continue;
			if (visited[nx][ny]) {
				if (dist[nx][ny] == cur_time + 1 && color[nx][ny] != cur_num && color[nx][ny] != 3) {
					color[nx][ny] = 3;
					cnt++;
				}
				continue;
			}

			visited[nx][ny] = true;
			dist[nx][ny] = cur_time + 1;
			color[nx][ny] = cur_num;
			q.push({ nx,ny, cur_time + 1, cur_num });

		}


	}

	return cnt;

}

void Back(int idx, int depth, int r_cnt, int g_cnt) {
	if (depth == r + g) {
		ans = max(ans, BFS());
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (back_visited[v[i].first][v[i].second]) continue;
		back_visited[v[i].first][v[i].second] = true;

		if (r_cnt < r) {
			back_v.push_back({ v[i], 1 });
			Back(i + 1, depth + 1, r_cnt + 1, g_cnt);
			back_v.pop_back();
		}
		if (g_cnt < g) {
			back_v.push_back({ v[i], 2 });
			Back(i + 1, depth + 1, r_cnt, g_cnt + 1);
			back_v.pop_back();
		}

		back_visited[v[i].first][v[i].second] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	//Back 시작. idx, depth, r, g
	Back(0, 0, 0, 0);

	cout << ans;
}