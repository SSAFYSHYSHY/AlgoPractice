#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int t, h, w, o, f, s_x, s_y, f_x, f_y;
bool visited[101][101];
int arr[101][101];

struct Node {
	int x, y, height, hp;
};

void Input() {
	memset(visited, false, sizeof(visited));
	memset(arr, 0, sizeof(arr));

	cin >> h >> w >> o >> f >> s_x >> s_y >> f_x >> f_y;

	for (int i = 0; i < o; i++) {
		int x, y, l;
		cin >> x >> y >> l;

		arr[x][y] = l;
	}
}

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 1 <= x && x <= h && 1 <= y && y <= w;
}

void BFS() {
	queue<Node> q;
	//초기 위치 및 초기 높이와 초기 hp 
	q.push({ s_x,s_y,0,f });
	visited[s_x][s_y] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ch = q.front().height;
		int chp = q.front().hp;
		q.pop();

		//도착 지점에 도달.
		if (cx == f_x && cy == f_y) {
			cout << "잘했어!!\n";
			return;
		}
		//만약 chp가 0 이하로 떨어지면 다른 경로 경우의 수.
		if (chp <= 0) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny) || visited[nx][ny]) continue;

			int nh = arr[nx][ny];

			if (nh > ch) {
				int jump = nh - ch;
				if (jump > chp) continue;
			}

			visited[nx][ny] = true;
			q.push({ nx,ny,nh, chp - 1 });
		}
	}

	//다 돌아도 못 돈 경우가 생겼으므로.
	cout << "인성 문제있어??\n";
}

int main() {
	cin >> t;

	while (t--) {
		Input();

		BFS();
	}

}