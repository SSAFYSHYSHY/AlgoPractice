#pragma once
//https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/pacman/description
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int m, t;
//팩맨 위치.
int s_x, s_y;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

int dx2[] = { -1,0,1,0 };
int dy2[] = { 0,-1,0,1 };

int arr[4][4];
vector<int> egg[4][4];
vector<int> kill[4][4];

struct Node {
	int x, y, dir;

};

vector<Node> v;

void Input() {
	cin >> m >> t;
	cin >> s_x >> s_y;

	s_x--;
	s_y--;

	for (int i = 0; i < m; i++) {
		int x, y, dir;

		cin >> x >> y >> dir;
		x--, y--, dir--;

		v.push_back({ x,y,dir });
	}

	//초기화.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			kill[i][j].clear();
			egg[i][j].clear();
		}
	}
}

void Plus() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (kill[i][j].size() > 0) {
				for (int k = 0; k < kill[i][j].size(); k++) {
					if (kill[i][j][k] < 2) {
						kill[i][j][k]++;
					}
				}
			}
		}
	}
}

void Copy() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		int dir = v[i].dir;

		egg[x][y].push_back(dir);
	}

}

bool InRange(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void Move() {
	for (int i = 0; i < v.size(); i++) {
		int cx = v[i].x;
		int cy = v[i].y;
		int cdir = v[i].dir;

		for (int j = 0; j < 8; j++) {
			int ndir = (cdir + j) % 8;
			int nx = cx + dx[ndir];
			int ny = cy + dy[ndir];

			if (!InRange(nx, ny)) continue;
			if (kill[nx][ny].size() > 0) continue;
			if (nx == s_x && ny == s_y) continue;

			v[i] = { nx,ny,ndir };
			break;
		}
	}
}

int Calc(vector<int> path) {
	int cx = s_x, cy = s_y;

	int cnt = 0;
	for (int i = 0; i < path.size(); i++) {
		cx += dx2[path[i]];
		cy += dy2[path[i]];

		//범위 밖에 나가면 아웃.
		if (!InRange(cx, cy)) return -1;

		for (int j = 0; j < v.size(); j++) {
			int nx = v[j].x;
			int ny = v[j].y;

			if (cx == nx && cy == ny) {
				cnt++;
			}
		}
	}

	return cnt;
}

void Pac(int idx, vector<int> path, vector<pair<int, vector<int>>>& real_path) {
	if (idx == 3) {
		int num = Calc(path);

		//-1이 아닌 경우 찐 경로.
		if (num != -1) {
			real_path.push_back({ num, path });
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		path.push_back(i);
		Pac(idx + 1, path, real_path);
		path.pop_back();
	}

}

bool cmp(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

void Move2(vector<int> path) {
	int cx = s_x;
	int cy = s_y;

	bool visited[4][4] = { false };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < path.size(); i++) {
		cx += dx2[path[i]];
		cy += dy2[path[i]];

		visited[cx][cy] = true;

		for (int j = 0; j < v.size(); j++) {
			int nx = v[j].x;
			int ny = v[j].y;

			if (cx == nx && cy == ny) {
				kill[nx][ny].push_back(0);
			}
		}
	}

	vector<Node> temp_v;
	for (int i = 0; i < v.size(); i++) {
		int cx = v[i].x;
		int cy = v[i].y;

		if (!visited[cx][cy]) {
			temp_v.push_back({ v[i].x, v[i].y, v[i].dir });
		}
	}

	//몬스터 갱신, 팩맨 좌표 재 갱신
	v = temp_v;
	s_x = cx;
	s_y = cy;
}

void Copy2() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (egg[i][j].size() > 0) {
				for (int k = 0; k < egg[i][j].size(); k++) {
					v.push_back({ i,j, egg[i][j][k] });
				}

				egg[i][j].clear();
			}
		}
	}
}

void Kill2() {
	vector<int> new_kill[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (kill[i][j].size() > 0) {
				for (int k = 0; k < kill[i][j].size(); k++) {
					if (kill[i][j][k] != 2) {
						new_kill[i][j].push_back(kill[i][j][k]);
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (new_kill[i][j].size() > 0) {
				kill[i][j] = new_kill[i][j];
			}
		}
	}
}

/*
3 4
3 3
2 4 3
1 2 5
4 3 8
*/

int main() {
	Input();

	while (t--) {

		//2. 몬스터 복제.
		Copy();

		//3. 몬스터 이동.
		Move();

		//4. 팩맨 이동.
		vector<int> path;
		vector<pair<int, vector<int>>> real_path;
		Pac(0, path, real_path);
		//4.1 가장 많이 먹은 것들과 우선순위 별로 정렬.
		sort(real_path.begin(), real_path.end(), cmp);
		vector<int> best_path = real_path[0].second;

		//4.2 가장 좋은 경로로 이동하며 먹음.
		Move2(best_path);

		//1. kill된 것들 +1;
		Plus();
		//6. 2초 경과한 것들 삭제.
		Kill2();

		//5.알 배열의 것들 v에 옮기기.
		Copy2();

	}

	//유령 크기
	cout << v.size() << "\n";
}