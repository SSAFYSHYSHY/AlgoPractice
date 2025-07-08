#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
queue<pair<int, int>> q;
bool visited[500001][2] = { false, };

int BFS() {
	q.push({ n,0 });
	visited[n][0] = true;
	int time = 0;

	while (1) {
		int brother = k + time * (time + 1) / 2;
		if (brother > 500000) return -1;
		if (visited[brother][time % 2]) return time;

		int size = q.size();

		for (int i = 0; i < size; i++) {
			int pos = q.front().first;
			int t = q.front().second;
			q.pop();

			for (int next : {pos - 1, pos + 1, pos * 2}) {
				if (0 <= next && next <= 500000 && !visited[next][(t + 1) % 2]) {
					visited[next][(t + 1) % 2] = true;
					q.push({ next, t + 1 });
				}
			}
		}

		time++;
	}
}

int main() {
	cin >> n >> k;

	if (n == k) {
		cout << 0;
	}
	else {
		cout << BFS();
	}
}


