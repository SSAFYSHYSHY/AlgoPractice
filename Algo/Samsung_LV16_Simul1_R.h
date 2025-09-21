//https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/cooling-system/description
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;

int arr[21][21];
int temp[21][21];
int temp2[21][21];

bool visited[21][21] = { false };
bool blocked[21][21][2] = { false };

int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

void Input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;

		blocked[x][y][dir] = true;
	}
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp2[i][j] += temp[i][j];
			cout << temp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	memset(temp, 0, sizeof(temp));
	memset(visited, false, sizeof(visited));
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Back(int x, int y, int dir, int num) {
	if (num == 0) return;
	//벽 체크. 1 이면 좌우체크, 0 이면 상하 체크.
	int ndir = (dir % 2 == 0) ? 1 : 0;

	visited[x][y] = true;

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	temp[nx][ny] = num;
	if (InRange(nx, ny) && !visited[nx][ny] && !blocked[nx][ny][ndir]) {
		Back(nx, ny, dir, num - 1);
	}

	//왼,오른일시 상,하로
	if (dir % 2 == 0) {
		int nxs[] = { x - 1, x + 1 };
		for (int i = 0; i < 2; i++) {
			int nx = nxs[i];
			int ny = y + dy[dir];

			//상하로 움직이는 경우에 대해.
			if (InRange(nx, ny) && !visited[nx][ny] && !blocked[nx][ny][0]) {
				Back(nx, ny, dir, num - 1);
			}
		}
	}
	//위, 아래
	else {
		int nys[] = { y - 1, y + 1 };
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[dir];
			int ny = nys[i];

			if (InRange(nx, ny) && !visited[nx][ny] && !blocked[nx][ny][1]) {
				Back(nx, ny, dir, num - 1);
			}
		}
	}
}

void Calc() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] >= 2) {
				if (arr[i][j] % 2 == 0) {
					Back(i, j, arr[i][j] - 2, 5);
				}
				else {
					Back(i, j, arr[i][j] - 2, 5);
				}

				Print();
			}
		}
	}

}

void Minus() {
	int temp3[21][21];


	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int remain = temp2[i][j];

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (InRange(nx, ny) && !blocked[nx][ny]) {
					if (temp2[i][j] > temp2[nx][ny]) {
						remain -= (temp2[i][j] - temp2[nx][ny]) / 4;
					}
					else {
						remain += (temp2[nx][ny] - temp2[i][j]) / 4;
					}
				}
			}

			temp2[i][j] = remain;
		}
	}


	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0 || j == 0 || i == n - 1 || j == n - 1) && temp2[i][j] > 0) {
				temp2[i][j]--;
			}
		}
	}

	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

int Sum() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				sum += temp2[i][j];
			}
		}
	}

	return sum;
}

int main() {

	Input();

	int cnt = 1;
	while (1) {
		//n 방향대로 진행.
		Calc();

		//각 자리수 차이 별로 감산, 겉에 -1 감산.
		Minus();

		//arr 1에 대해서 sum 연산.
		int sum = Sum();

		//k 이상인 경우에 대해
		if (sum >= k) {
			cout << cnt;
			return 0;
		}

		//100 이상이면 -1 종료.
		cnt++;
		if (cnt >= 100) {
			cout << -1 << "\n";
			return 0;
		}
	}

}#pragma once
