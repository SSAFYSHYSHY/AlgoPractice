#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int t, n, m;
char arr[51][51];
bool visited[51][51][51][51];

int sx, sy, sx2, sy2;
vector<int> ans;

struct Node {
	int ax, ay, bx, by;
};

void Input() {
	memset(arr, '.', sizeof(arr));
	memset(visited, false, sizeof(visited));

	cin >> n >> m;

	bool flag = false;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'P') {
				if (!flag) {
					sx = i;
					sy = j;
					flag = true;
				}
				else {
					sx2 = i;
					sy2 = j;
				}
			}
		}
	}
}

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int sx, int sy, int sx2, int sy2) {
	queue<pair<Node, vector<int>>> q;
	q.push({ {sx,sy,sx2,sy2}, {} });
	visited[sx][sy][sx2][sy2] = true;

	while (!q.empty()) {
		Node cur = q.front().first;
		vector<int> cpath = q.front().second;
		q.pop();

		//조건 만족시 cpath가 가장 짧은 길이가 됨.
		if (cur.ax == cur.bx && cur.ay == cur.by) {
			ans = cpath;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.ax + dx[i];
			int ny = cur.ay + dy[i];
			int nx2 = cur.bx + dx[i];
			int ny2 = cur.by + dy[i];

			//범위 밖에 벗어나면 다시 좌표 0 혹은 n,m의 위치로 돌아가는 처리 다시 n , m을 더하는 방법의 연산으로 처리.
			nx = (nx + n) % n;
			ny = (ny + m) % m;
			nx2 = (nx2 + n) % n;
			ny2 = (ny2 + m) % m;

			//벽 마주할시 그냥 좌표는 멈춤.
			if (arr[nx][ny] == 'X') { nx = cur.ax; ny = cur.ay; }
			if (arr[nx2][ny2] == 'X') { nx2 = cur.bx; ny2 = cur.by; }

			//해당 연산 미래 예외 처리.
			if (arr[nx][ny] == 'G' || arr[nx2][ny2] == 'G') continue;
			if (visited[nx][ny][nx2][ny2]) continue;

			if (!visited[nx][ny][nx2][ny2]) {
				vector<int> npath = cpath;
				visited[nx][ny][nx2][ny2] = true;
				npath.push_back(i);
				q.push({ { nx,ny,nx2,ny2 }, npath });
			}
		}


	}

}

int main() {
	cin >> t;

	while (t--) {
		Input();

		BFS(sx, sy, sx2, sy2);

		if (ans.empty()) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << ans.size() << " ";
			for (int i = 0; i < ans.size(); i++) {
				if (ans[i] == 0) cout << "N";
				else if (ans[i] == 1) cout << "S";
				else if (ans[i] == 2) cout << "W";
				else if (ans[i] == 3) cout << "E";
			}
			cout << "\n";
		}


		ans.clear();
	}

}