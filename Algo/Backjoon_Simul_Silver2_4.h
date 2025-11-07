#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, sx, sy;
char arr[11][11];
bool visited[11][11] = { false, };
vector<int> v;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

string dir[] = { "dolje", "gore", "lijevo", "desno" };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'P') {
				sx = i;
				sy = j;
			}
		}
	}

	bool flag = false;
	int cnt = 100;
	while (cnt > 0) {
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 'x') {
				v.push_back(i);
				visited[nx][ny] = true;
				sx = nx;
				sy = ny;
			}
		}
		cnt--;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << dir[v[i]] << "\n";
	}
}