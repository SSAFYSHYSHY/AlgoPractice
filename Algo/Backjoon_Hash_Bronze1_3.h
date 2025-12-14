#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

bool visited[2002][2002] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int sx = 1000, sy = 1000, ans = 0;

int main() {
	memset(visited, false, sizeof(visited));
	string s;
	int num;
	cin >> num;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'N') {
			sx += dx[0];
			sy += dy[0];

			if (!visited[sx][sy]) {
				visited[sx][sy] = true;
				ans++;
			}
		}
		else if (s[i] == 'S') {
			sx += dx[1];
			sy += dy[1];

			if (!visited[sx][sy]) {
				visited[sx][sy] = true;
				ans++;
			}
		}
		else if (s[i] == 'W') {
			sx += dx[2];
			sy += dy[2];

			if (!visited[sx][sy]) {
				visited[sx][sy] = true;
				ans++;
			}
		}
		else if (s[i] == 'E') {
			sx += dx[3];
			sy += dy[3];

			if (!visited[sx][sy]) {
				visited[sx][sy] = true;
				ans++;
			}
		}
	}

	cout << ans;
}