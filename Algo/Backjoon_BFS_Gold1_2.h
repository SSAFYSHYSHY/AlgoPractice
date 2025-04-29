#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
char arr[11][11];
bool visited[11][11][11][11];
pair<int, int> red, blue;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int rx, ry, bx, by, cnt;
};

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'R') {
				red.first = i;
				red.second = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				blue.first = i;
				blue.second = j;
				arr[i][j] = '.';
			}
		}
	}
}

int BFS() {
	memset(visited, false, sizeof(visited));
	queue<Node> q;
	q.push({ red.first, red.second, blue.first, blue.second, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		int crx = q.front().rx;
		int cry = q.front().ry;
		int cbx = q.front().bx;
		int cby = q.front().by;
		int ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			bool red_check = false, blue_check = false;

			int nrx = crx + dx[i];
			int nry = cry + dy[i];
			int nbx = cbx + dx[i];
			int nby = cby + dy[i];
			int ncnt = ccnt + 1;

			//Red Âß ÀÌµ¿.
			while (1) {
				if (arr[nrx][nry] == '#') break;
				if (arr[nrx][nry] == 'O') {
					red_check = true;
					break;
				}

				nrx += dx[i];
				nry += dy[i];
			}
			nrx = nrx - dx[i];
			nry = nry - dy[i];

			//Blue Âß ÀÌµ¿.
			while (1) {
				if (arr[nbx][nby] == '#') break;
				if (arr[nbx][nby] == 'O') {
					blue_check = true;
					break;
				}

				nbx += dx[i];
				nby += dy[i];
			}
			nbx = nbx - dx[i];
			nby = nby - dy[i];

			//blue°¡ ´ê¾ÒÀ¸¸é ³¡.
			if (blue_check) continue;
			if (red_check) {
				return ncnt;
			}

			if (nrx == nbx && nry == nby) {
				int rdist = abs(crx - nrx) + abs(cry - nry);
				int bdist = abs(cbx - nbx) + abs(cby - nby);

				if (rdist > bdist) {
					nrx = nrx - dx[i];
					nry = nry - dy[i];
				}
				else {
					nbx = nbx - dx[i];
					nby = nby - dy[i];
				}
			}

			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby,ncnt });
			}
		}
	}

	return -1;
}

int main() {
	Input();
	int num = BFS();

	if (num == -1) {
		cout << -1;
	}
	else {
		cout << num;
	}
}