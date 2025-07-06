#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int n;
int leftc[MAX], rightc[MAX], parent[MAX];
bool visited[MAX];
int endNode;
int movecnt = 0;
bool finished = false;

void Find(int node) {
	if (node == -1) return;

	Find(leftc[node]);
	endNode = node;
	Find(rightc[node]);
}

void traverse(int node) {
	visited[node] = true;

	if (!finished && leftc[node] != -1 && !visited[leftc[node]]) {
		movecnt++;
		traverse(leftc[node]);
		if (finished) return;
	}

	if (!finished && rightc[node] != -1 && !visited[rightc[node]]) {
		movecnt++;
		traverse(rightc[node]);
		if (finished) return;
	}

	if (node == endNode) {
		finished = true;
		return;
	}

	if (!finished && parent[node] != 0) {
		movecnt++;
		traverse(parent[node]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		leftc[a] = b;
		rightc[a] = c;

		if (b != -1) parent[b] = a;
		if (c != -1) parent[c] = a;

	}

	Find(1);

	traverse(1);

	cout << movecnt;
}