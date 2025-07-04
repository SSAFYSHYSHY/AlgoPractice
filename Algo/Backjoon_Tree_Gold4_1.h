#pragma once
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10001;

int t, n;
vector<int> v[MAX];
int parent[MAX];
int depth[MAX];

bool visited[MAX] = { false };
bool isChild[MAX] = { false };

void Initial() {
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	memset(depth, 0, sizeof(depth));
	memset(isChild, false, sizeof(isChild));

	for (int i = 0; i < n; i++) {
		v[i].clear();
	}
}

void DFS(int node, int d) {
	visited[node] = true;
	depth[node] = d;

	for (int next : v[node]) {
		if (!visited[next]) {
			parent[next] = node;
			DFS(next, d + 1);
		}
	}
}

int LCA(int a, int b) {
	while (depth[a] > depth[b]) a = parent[a];
	while (depth[b] > depth[a]) b = parent[b];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

//부모 노드 찾기.
//자식 노드가 false이면 부모노드가 없다는 소리이니 해당 수 반환
int Find() {
	for (int i = 1; i <= n; i++) {
		if (!isChild[i]) {
			return i;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		Initial();

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;

			v[x].push_back(y);
			v[y].push_back(x);

			isChild[y] = true;
		}

		int root = Find();
		DFS(root, 0);

		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << "\n";
	}
}