#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, root;
int level[100001];
vector<int> v[100001];

void DFS(int now) {
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		level[next] = level[now] + 1;
		DFS(next);
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		if (num == -1) root = i;
		else {
			v[num].push_back(i);
		}
	}

	DFS(root);

	for (int i = 1; i <= n; i++) {
		cout << level[i] << "\n";
	}

}