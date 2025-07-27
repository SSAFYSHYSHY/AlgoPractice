#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int n, m;
char arr[501][501];
int dist[501][501];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int s_x, s_y, e_x, e_y;

void Input() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
			dist[i][j] = INT_MAX;

			if (arr[i][j] == 'T') {
				s_x = i;
				s_y = j;
			}
			else if (arr[i][j] == 'E') {
				e_x = i;
				e_y = j;
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

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int Dijk() {
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, s_x,s_y });
	dist[s_x][s_y] = 0;

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cx = pq.top().x;
		int cy = pq.top().y;
		pq.pop();

		if (cx == e_x && cy == e_y) {
			return cost;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx;
			int ny = cy;
			bool flag = false;
			int temp = cost;

			while (1) {
				if (!InRange(nx, ny) || arr[nx][ny] == 'H') {
					flag = false;
					break;
				}
				if (arr[nx + dx[i]][ny + dy[i]] == 'R') {
					flag = true;
					break;
				}

				nx += dx[i];
				ny += dy[i];


				if (arr[nx][ny] == 'E') {
					flag = true;
					break;
				}

				temp += (int)(arr[nx][ny] - '0');
			}

			//flag »ýÁ¸.
			if (flag) {
				if (temp < dist[nx][ny]) {
					dist[nx][ny] = temp;
					pq.push({ temp, nx,ny });
				}
			}
			else {
				continue;
			}
		}
	}

	return -1;
}

int main() {
	Input();

	cout << Dijk() << "\n";

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R' || arr[i][j] == 'H' || arr[i][j] == 'E' || arr[i][j] == 'T') {
				cout << arr[i][j] << " ";
			}
			else {
				if (dist[i][j] == INT_MAX) {
					cout << "X ";
				}
				else {
					cout << dist[i][j] << " ";
				}
			}
		}
		cout << "\n";
	}*/
}