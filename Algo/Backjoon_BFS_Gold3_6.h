#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
vector <int> v[3010];
int res[3010];

bool visited[3010] = { false, };

bool cur_road[3010] = { false, };
bool flag_cur = false;

void dfs(int start, int num, int line) {

	visited[num] = true;
	cur_road[num] = true;

	int curr;
	for (int i = 0; i < v[num].size(); i++) {
		curr = v[num][i];
		if (curr == start && line >= 2) {
			flag_cur = true;
			return;
		}

		if (visited[curr]) continue;
		dfs(start, curr, line + 1);

		if (flag_cur) return;
	}

	visited[num] = false;
	if (!flag_cur) cur_road[num] = false;
}


void DFS() {
	for (int i = 1; i <= N; i++) {
		if (!flag_cur) dfs(i, i, 0);
		else return;
	}

}

void bfs(int num) {
	queue<int>q;
	bool visited[3010] = { false, };

	q.push(num);
	visited[num] = true;

	int curr, next;
	int cnt = 0;

	while (!q.empty()) {
		int size = q.size();

		cnt++;
		for (int s = 0; s < size; s++) {
			curr = q.front();
			q.pop();
			if (cur_road[curr]) {
				res[num] = --cnt;
				return;
			}
			for (int i = 0; i < v[curr].size(); i++) {
				next = v[curr][i];
				if (visited[next]) continue;
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

void BFS() {

	for (int i = 1; i <= N; i++) {
		if (!cur_road[i]) bfs(i);
		else res[i] = 0;
	}
}

void Calc() {
	DFS();
	BFS();

	for (int i = 1; i <= N; i++)
		cout << res[i] << " ";

	cout << endl;

}

int main()
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < 3010; i++)
		sort(v[i].begin(), v[i].end());

	Calc();
	return 0;
}