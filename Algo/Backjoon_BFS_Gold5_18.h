#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

char arr[9][9];
bool visited[9][9][9][9];

int swx, swy, sbx, sby;
int ewx, ewy, ebx, eby;

bool flag = false;

int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

struct Node {
	int wx, wy, bx, by;
};

struct Parent {
	int pwx, pwy, pbx, pby;
	char moved;
} parent_state[8][8][8][8];

bool InRange(int x, int y) {
	return 0 <= x && x < 8 && 0 <= y && y < 8;
}

void BFS(int swx, int swy, int sbx, int sby, int ewx, int ewy, int ebx, int eby) {
	queue<Node> q;
	visited[swx][swy][sbx][sby] = true;
	q.push({ swx,swy,sbx,sby });
	parent_state[swx][swy][sbx][sby] = { -1,-1,-1,-1,'?' };

	while (!q.empty()) {
		int cwx = q.front().wx;
		int cwy = q.front().wy;
		int cbx = q.front().bx;
		int cby = q.front().by;
		q.pop();

		if (cwx == ewx && cwy == ewy && cbx == ebx && cby == eby) {
			flag = true;
			break;
		}

		//white x,y
		for (int i = 0; i < 8; i++) {
			int nwx = cwx + dx[i];
			int nwy = cwy + dy[i];

			if (!InRange(nwx, nwy)) continue;
			if (nwx == cbx && nwy == cby) continue;

			if (!visited[nwx][nwy][cbx][cby]) {
				visited[nwx][nwy][cbx][cby] = true;
				parent_state[nwx][nwy][cbx][cby] = { cwx,cwy,cbx,cby, 'W' };
				q.push({ nwx,nwy,cbx,cby });
			}
		}

		//black x,y
		for (int i = 0; i < 8; i++) {
			int nbx = cbx + dx[i];
			int nby = cby + dy[i];

			if (!InRange(nbx, nby)) continue;
			if (nbx == cwx && nby == cwy) continue;

			if (!visited[cwx][cwy][nbx][nby]) {
				visited[cwx][cwy][nbx][nby] = true;
				parent_state[cwx][cwy][nbx][nby] = { cwx,cwy,cbx,cby,'B' };
				q.push({ cwx,cwy,nbx,nby });
			}
		}
	}
}

int main() {
	memset(visited, false, sizeof(visited));

	string a, b, c, d;
	cin >> a >> b >> c >> d;

	swx = a[0] - 'a';
	swy = (a[1] - '0') - 1;

	sbx = b[0] - 'a';
	sby = (b[1] - '0') - 1;

	ewx = c[0] - 'a';
	ewy = (c[1] - '0') - 1;

	ebx = d[0] - 'a';
	eby = (d[1] - '0') - 1;

	BFS(swx, swy, sbx, sby, ewx, ewy, ebx, eby);


	if (!flag) {
		cout << -1;
		return 0;
	}

	vector<string> moves;
	int x = ewx, y = ewy, X = ebx, Y = eby;

	while (1) {
		Parent p = parent_state[x][y][X][Y];
		if (p.pwx == -1) break;

		char mv = p.moved;
		char file = (mv == 'W' ? x : X) + 'a';
		char rank = (mv == 'W' ? y : Y) + '1';

		string cmd = string(1, mv) + " " + string(1, file) + string(1, rank);
		moves.push_back(cmd);

		int nx = p.pwx, ny = p.pwy, nX = p.pbx, nY = p.pby;
		x = nx;
		y = ny;
		X = nX;
		Y = nY;
	}

	reverse(moves.begin(), moves.end());
	cout << moves.size() << "\n";
	for (string s : moves) {
		cout << s << "\n";
	}
}