#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool flag = true;
vector<int> v[100001];
bool visited[100001] = { false, };
vector<int> ans;

void Input() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		ans.push_back(num);
	}
}

void BFS() {
	if (ans[0] != 1) {
		flag = false;
		return;
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int idx = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		vector<int> temp;

		for (int next : v[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				temp.push_back(next);
			}
		}

		int cnt = temp.size();
		for (int i = idx; i < idx + cnt; i++) {
			if (i >= n || find(temp.begin(), temp.end(), ans[i]) == temp.end()) {
				flag = false;
				return;
			}
		}

		for (int i = idx; i < idx + cnt; i++) {
			q.push(ans[i]);
		}

		idx += cnt;
	}


}

int main() {
	Input();

	BFS();

	if (!flag) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}