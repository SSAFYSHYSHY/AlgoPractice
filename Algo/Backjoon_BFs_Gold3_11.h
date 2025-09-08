#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

char arr[21][21];
bool visited[21][21][21][21];
int n, m, ans = -1;

int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };

struct Node {
	int ax, ay;
	int bx, by;
	int turn;
};

int eax, eay, ebx, eby;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'A') {
				eax = i;
				eay = j;
			}
			else if (arr[i][j] == 'B') {
				ebx = i;
				eby = j;
			}
		}
	}

	memset(visited, false, sizeof(visited));
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int sax, int say, int sbx, int sby) {
	queue<Node> q;
	q.push({ sax, say , sbx, sby , 0 });
	visited[sax][say][sbx][sby] = true;

	while (!q.empty()) {
		int cax = q.front().ax;
		int cay = q.front().ay;

		int cbx = q.front().bx;
		int cby = q.front().by;
		int ccnt = q.front().turn;
		q.pop();

		if (cax == ebx && cay == eby && cbx == eax && cby == eay) {
			ans = max(ans, ccnt);
			return;
		}


		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int nax = cax + dx[i];
				int nay = cay + dy[i];
				int nbx = cbx + dx[j];
				int nby = cby + dy[j];

				//범위 산정.
				if (!InRange(nax, nay) || !InRange(nbx, nby)) continue;
				//방문되어 있으면 스킵.
				if (visited[nax][nay][nbx][nby]) continue;
				//벽.
				if (arr[nax][nay] == 'X' || arr[nbx][nby] == 'X') continue;
				//현재 위치와의 비교해서 같은 A,B 좌표에 대해 continue;
				if ((nax == nbx && nay == nby) || (nax == cbx && nay == cby && nbx == cax && nby == cay)) continue;

				visited[nax][nay][nbx][nby] = true;
				q.push({ nax, nay,nbx, nby, ccnt + 1 });
			}
		}


	}

	return;
}

int main() {
	Input();

	BFS(eax, eay, ebx, eby);

	cout << ans;
}