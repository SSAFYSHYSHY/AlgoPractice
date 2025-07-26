#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
char arr[501][501];
int dist[501][501];

int s_x, s_y, e_x, e_y;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
			dist[i][j] = INT_MAX;

			if (arr[i][j] == 'E') {
				e_x = i;
				e_y = j;
			}
			else if (arr[i][j] == 'S') {
				s_x = i;
				s_y = j;
			}
		}
	}
}

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Calc(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//범위 안에 없고, 이미 방문이 되어버린 조건이면.
		if (!InRange(nx, ny)) continue;
		if (dist[nx][ny] != INT_MAX) continue;

		//# 벽 발견시.
		if (arr[nx][ny] == '#') return false;
	}

	return true;
}

void Dijk() {
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, s_x, s_y });
	dist[s_x][s_y] = 0;

	bool first = true, second = true;

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cx = pq.top().x;
		int cy = pq.top().y;
		pq.pop();

		//현 위치에서 4 방향을 색출.
		first = Calc(cx, cy);
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			//범위 안이 아니고 , dist 값이 정해져 있고, 가고자 하는 곳이 벽이면 탐색 스킵.
			if (!InRange(nx, ny)) continue;
			//if (dist[nx][ny] != INT_MAX) continue;
			if (arr[nx][ny] == '#') continue;

			//가고자 하는 방향의 다시 4 방향을 탐색;
			second = Calc(nx, ny);

			//cost 증가 조건.
			if ((first == true && second == true) || (first == true && second == false) || (first == false && second == true)) {
				if (cost + 1 < dist[nx][ny]) {
					dist[nx][ny] = cost + 1;
					pq.push({ cost + 1, nx,ny });
				}
			}
			else {
				if (cost < dist[nx][ny]) {
					dist[nx][ny] = cost;
					pq.push({ cost , nx,ny });
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

	Dijk();

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		if (arr[i][j] == '#') cout << "# ";
	//		else {
	//			cout << dist[i][j] << " ";
	//		}
	//	}
	//	cout << "\n";
	//}

	cout << dist[e_x][e_y];
}