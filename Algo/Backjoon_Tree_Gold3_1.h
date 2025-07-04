#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 60001;

vector<int> v[MAX];
int parent[MAX];
int depth[MAX];
bool visited[MAX];
int n, m;


//Ʈ�� ���� + ���̿� �θ� ���.
void DFS(int node, int d) {
	visited[node] = true;
	//����.
	depth[node] = d;

	for (int next : v[node]) {
		if (!visited[next]) {
			parent[next] = node;
			DFS(next, d + 1);
		}
	}

}

int LCA(int a, int b) {
	//�� ���� ���� ���� �ø�.
	while (depth[a] > depth[b]) a = parent[a];
	while (depth[b] > depth[a]) b = parent[b];

	//������������ ���� �ö�.
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	//��Ʈ 1 ��.
	DFS(1, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		cout << LCA(x, y) << "\n";
	}
}