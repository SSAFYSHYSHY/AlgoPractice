#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[1000005];
vector<int> truth;

int Find(int n) {
	if (arr[n] == n) return n;
	else return arr[n] = Find(arr[n]);
}

void Merge(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	arr[b] = a;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;

			if (num == 1) {
				Merge(i, j);
			}
		}
	}

	int x, cnt = 0;
	cin >> x;

	for (int i = 1; i < m; i++) {
		int num;
		cin >> num;

		if (Find(x) == Find(num)) {
			cnt++;
		}
		else break;
		x = num;
	}

	if (cnt == m - 1) cout << "YES";
	else {
		cout << "NO";
	}
}