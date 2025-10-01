#pragma once
#include <iostream>

using namespace std;

int N;
int ans = 0;
bool visited[13];
int arr[25];

void func(int idx) {
	if (idx > N) {
		ans++;
		return;
	}

	if (visited[idx]) func(idx + 1);
	else {
		int R = 2 * N - idx - 1;
		for (int i = 1; i <= R; i++) {
			int temp = i + idx + 1;
			if (!arr[i] && !arr[temp]) {
				arr[i] = arr[temp] = idx;
				func(idx + 1);
				arr[i] = arr[temp] = 0;
			}
		}
	}
}

int main() {
	int x, y; cin >> N >> x >> y;

	arr[x] = arr[y] = y - x - 1;
	visited[y - x - 1] = 1;

	func(1);

	cout << ans;
}