#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n, m, ans = 0;
int arr[1001][1001];
bool visited[1001][1001];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = (int)(s[j] - '0');
		}
	}
}

struct Node {
	int x, y;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int x, int y) {
	queue<Node> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	//�� ����.
	for (int i = 0; i < n; i++) {
		if (!visited[i][0] && arr[i][0] == 0) {
			BFS(i, 0);
		}
		if (!visited[i][m - 1] && arr[i][m - 1] == 0) {
			BFS(i, m - 1);
		}
	}

	//�� ����.
	for (int j = 0; j < m; j++) {
		if (!visited[0][j] && arr[0][j] == 0) {
			BFS(0, j);
		}
		if (!visited[n - 1][j] && arr[n - 1][j] == 0) {
			BFS(n - 1, j);
		}
	}

	//��Ž���� 1 �� ������ Ȯ��.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//���� �����̸�.
			if (arr[i][j] == 1) {
				//4 ���� Ž���ؼ�.
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					//���� ���̸�.
					if (!InRange(nx, ny)) ans++;
					//���� �ȿ� �ִµ� �湮�� 1 �� �ٴٸ�.
					else if (InRange(nx, ny) && visited[nx][ny] && arr[nx][ny] == 0) {
						ans++;
					}
				}

			}
		}
	}

	cout << ans;

}