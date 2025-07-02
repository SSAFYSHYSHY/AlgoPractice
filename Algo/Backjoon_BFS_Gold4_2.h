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
	//�ʱ� ��ġ �� �ʱ� ���̿� �ʱ� hp 
	q.push({ s_x,s_y,0,f });
	visited[s_x][s_y] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ch = q.front().height;
		int chp = q.front().hp;
		q.pop();

		//���� ������ ����.
		if (cx == f_x && cy == f_y) {
			cout << "���߾�!!\n";
			return;
		}
		//���� chp�� 0 ���Ϸ� �������� �ٸ� ��� ����� ��.
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

	//�� ���Ƶ� �� �� ��찡 �������Ƿ�.
	cout << "�μ� �����־�??\n";
}

int main() {
	cin >> t;

	while (t--) {
		Input();

		BFS();
	}

}