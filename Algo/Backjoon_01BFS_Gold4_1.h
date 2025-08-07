#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int t;
int f, n, m;
int s_h, s_x, s_y, e_h, e_x, e_y;

vector<vector<vector<char>>> v;
vector<vector<vector<int>>> dist;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int hdx[] = { -1,0,1 };

void Input() {
	cin >> f >> n >> m;


	v = vector<vector<vector<char>>>(f, vector<vector<char>>(n, vector<char>(m)));
	dist = vector<vector<vector<int>>>(f, vector<vector<int>>(n, vector<int>(m, INT_MAX)));

	for (int i = 0; i < f; i++) {

		for (int j = 0; j < n; j++) {
			string s;
			cin >> s;

			for (int k = 0; k < s.length(); k++) {
				v[i][j][k] = s[k];
				dist[i][j][k] = INT_MAX;

				if (v[i][j][k] == 'S') {
					s_h = i;
					s_x = j;
					s_y = k;
				}
				else if (v[i][j][k] == 'E') {
					e_h = i;
					e_x = j;
					e_y = k;
				}
			}
		}
	}
}

struct Node {
	int h, x, y;
};

bool InHeight(int x) {
	return 0 <= x && x < f;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	deque<Node> dq;
	dist[s_h][s_x][s_y] = 0;
	dq.push_front({ s_h, s_x, s_y });

	while (!dq.empty()) {
		int ch = dq.front().h;
		int cx = dq.front().x;
		int cy = dq.front().y;
		dq.pop_front();

		if (ch == e_h && cx == e_x && cy == e_y) {
			return;
		}

		for (int i = 0; i < 3; i++) {
			int nh = ch + hdx[i];
			int nx = cx;
			int ny = cy;

			if (!InHeight(nh)) continue;

			int cost = (v[nh][nx][ny] == '#' ? 1 : 0);

			if (dist[nh][nx][ny] > dist[ch][cx][cy] + cost) {
				dist[nh][nx][ny] = dist[ch][cx][cy] + cost;

				if (cost == 0) {
					dq.push_front({ nh,nx,ny });
				}
				else {
					dq.push_back({ nh,nx,ny });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nh = ch;
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;

			int cost = (v[nh][nx][ny] == '#' ? 1 : 0);

			if (dist[nh][nx][ny] > dist[ch][cx][cy] + cost) {
				dist[nh][nx][ny] = dist[ch][cx][cy] + cost;

				if (cost == 0) {
					dq.push_front({ nh,nx,ny });
				}
				else {
					dq.push_back({ nh,nx,ny });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {

		Input();

		BFS();

		cout << dist[e_h][e_x][e_y] << "\n";

		//for (int i = 0; i < f; i++) {
		//	for (int j = 0; j < n; j++) {
		//		for (int k = 0; k < m; k++) {

		//			if (dist[i][j][k] == INT_MAX) {
		//				cout << "X ";
		//			}
		//			else {
		//				cout << dist[i][j][k] << " ";
		//			}
		//		}
		//		cout << "\n";
		//	}
		//	cout << "\n\n";
		//}
		//cout << "\n\n";
	}


}