#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
char arr[1501][1501];
bool visited[1501][1501];
bool melt_visited[1501][1501];

//현재 처리해야 하는 상황, 현재 처리에서 다음 처리해야 할 영역을 저장하는 영역
queue<pair<int, int>> swan_q, swan_nq;
queue<pair<int, int>> water_q, water_nq;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

pair<int, int> start, endi;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Met() {
	while (!swan_q.empty()) {
		int cx = swan_q.front().first;
		int cy = swan_q.front().second;
		swan_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny]) {
				visited[nx][ny] = true;

				if (arr[nx][ny] == '.') {
					swan_q.push({ nx,ny });
				}
				else if (arr[nx][ny] == 'X') {
					swan_nq.push({ nx,ny });
				}
				else if (nx == endi.first && ny == endi.second) {
					return true;
				}
			}
		}
	}

	return false;
}

void Melt() {
	while (!water_q.empty()) {
		int x = water_q.front().first;
		int y = water_q.front().second;
		water_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !melt_visited[nx][ny]) {
				if (arr[nx][ny] == 'X') {
					melt_visited[nx][ny] = true;
					arr[nx][ny] = '.';
					water_nq.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	bool flag = false;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];

			if (arr[i][j] != 'X') {
				water_q.push({ i,j });
				melt_visited[i][j] = true;
			}
			
			if (arr[i][j] == 'L') {
				if (!flag) {
					start = { i,j };
					flag = true;
				}
				else {
					endi = { i,j };
				}
			}
		}
	}

	swan_q.push(start);
	visited[start.first][start.second] = true;

	int date = 0;
	while (1) {
		if (Met()) {
			cout << date << "\n";
			break;
		}

		Melt();
		swan_q = swan_nq;
		water_q = water_nq;
		while (!swan_nq.empty()) swan_nq.pop();
		while (!water_nq.empty()) water_nq.pop();
		date++;
	}
}