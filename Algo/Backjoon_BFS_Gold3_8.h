#pragma once
//path를 pair<int, vector<int>> 로 관리.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
bool visited[1000001];
vector<int> v;

void Calc(int cur) {
	if (cur > 1000000) return;
	if (cur != 0) v.push_back(cur);
	Calc(cur * 10 + 4);
	Calc(cur * 10 + 7);
}

vector<int> BFS() {
	queue<pair<int, vector<int>>> q;
	q.push({ 0, {} });
	visited[0] = true;

	while (!q.empty()) {
		pair<int, vector<int>> node = q.front();
		q.pop();

		int sum = node.first;
		vector<int> path = node.second;

		if (sum == n) return path;

		for (int i = 0; i < (int)v.size(); i++) {
			int x = v[i];
			int ns = sum + x;

			if (ns > n) continue;
			if (visited[ns]) continue;

			visited[ns] = true;

			vector<int> np = path;
			np.push_back(x);
			q.push({ ns, np });
		}

	}

	return vector<int>();
}

int main() {
	memset(visited, false, sizeof(visited));
	cin >> n;

	Calc(0);
	sort(v.begin(), v.end());

	vector<int> ans = BFS();

	if (ans.empty()) {
		cout << -1 << '\n';
	}
	else {
		for (int x : ans) {
			cout << x << " ";
		}
	}
}