#pragma once
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, s, d, f, b, k;
bool visited[100001] = { false, };
char arr[100001];

void Input() {
	memset(visited, false, sizeof(visited));
	memset(arr, '.', sizeof(arr));

	cin >> n >> s >> d >> f >> b >> k;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;

		arr[num] = 'X';
	}
}

struct Node {
	int x, cnt;
};

bool InRange(int x) {
	return 1 <= x && x < 100001;
}

void BFS(int s_x) {
	queue<Node> q;
	q.push({ s_x, 0 });
	visited[s_x] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int ccnt = q.front().cnt;
		q.pop();

		if (cx == d) {
			cout << ccnt;
			return;
		}

		int nx = cx + f;
		if (InRange(nx) && !visited[nx] && arr[nx] == '.') {
			q.push({ nx, ccnt + 1 });
			visited[nx] = true;
		}

		int nx2 = cx - b;
		if (InRange(nx2) && !visited[nx2] && arr[nx2] == '.') {
			q.push({ nx2,ccnt + 1 });
			visited[nx2] = true;
		}
	}

	cout << "BUG FOUND";
	return;
}

int main() {
	Input();

	BFS(s);

}