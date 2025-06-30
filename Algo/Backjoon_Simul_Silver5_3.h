#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
char arr[101][101];

int dx[] = { -1,-1,-1,0,0,1,1, 1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Calc() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			int cnt = 0;
			if (arr[i][j] == '.') {

				for (int k = 0; k < 8; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (InRange(nx, ny) && arr[nx][ny] == '*') {
						cnt++;
					}
				}
			}
			else if (arr[i][j] == '*') {
				continue;
			}

			arr[i][j] = (char)(cnt + '0');
		}
	}
}

int main() {

	while (1) {
		memset(arr, '.', sizeof(arr));

		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = s[j];
			}
		}

		//¿¬»ê.
		Calc();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
}