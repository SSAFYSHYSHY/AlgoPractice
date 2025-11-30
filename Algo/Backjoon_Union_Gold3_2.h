#pragma once
//이중 배열을 유니온-파인드로 조합하는 방법.

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int parent[1000001];
int arr[1001][1001];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
unordered_set<int> set;

int n, m;

int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'U') arr[i][j] = 0;
			else if (s[j] == 'D') arr[i][j] = 1;
			else if (s[j] == 'L') arr[i][j] = 2;
			else if (s[j] == 'R') arr[i][j] = 3;
		}
	}

	for (int i = 0; i < n * m; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int curr = m * i + j;
			int dir = arr[i][j];

			int nx = i + dx[dir];
			int ny = j + dy[dir];

			int next = m * nx + ny;

			Union(next, curr);
		}
	}

	for (int i = 0; i < n * m; i++) Find(i);
	for (int i = 0; i < n * m; i++) {
		set.insert(parent[i]);
	}
	cout << set.size();

}