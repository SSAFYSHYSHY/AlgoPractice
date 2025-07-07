#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, real_ans = 21e8;
int points[11];

//BFS 관련.
bool visited[11] = { false, };
vector<int> v[11];

//백트래킹 조건.
vector<int> back;
bool back_visited[11] = { false, };

void Input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> points[i];
	}

	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; j++) {
			int num;
			cin >> num;

			v[i].push_back(num);
			v[num].push_back(i);
		}
	}
}

bool Calc(const vector<int>& v2) {
	if (v2.empty()) return false;
	memset(visited, false, sizeof(visited));
	queue<int> q;

	q.push(v2[0]);
	visited[v2[0]] = true;

	int cnt = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			//방문한 적이 없고.
			//만약 v2 끝에도 찾지 못한다면.
			if (!visited[next] && find(v2.begin(), v2.end(), next) != v2.end()) {
				visited[next] = true;
				cnt++;
				q.push(next);
			}
		}
	}

	return cnt == v2.size();
}

int BFS() {
	vector<int> gA = back;
	vector<int> gB;

	for (int i = 1; i <= n; i++) {
		if (!back_visited[i]) {
			gB.push_back(i);
		}
	}

	//연결되어 있는가.
	if (!Calc(gA) || !Calc(gB)) return 21e8;

	//포인트 합.
	int sa = 0, sb = 0;
	for (int i = 0; i < gA.size(); i++) {
		sa += points[gA[i]];
	}
	for (int i = 0; i < gB.size(); i++) {
		sb += points[gB[i]];
	}

	return abs(sa - sb);

}

void Back(int idx, int now, int ans) {
	if (now == ans) {
		real_ans = min(real_ans, BFS());
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (!back_visited[i]) {
			back_visited[i] = true;
			back.push_back(i);
			Back(i, now + 1, ans);
			back.pop_back();
			back_visited[i] = false;
		}
	}
}

int main() {
	Input();

	for (int i = 1; i <= n / 2; i++) {
		Back(1, 0, i);
	}

	if (real_ans == 21e8) {
		cout << -1;
		return 0;
	}

	cout << real_ans;
}