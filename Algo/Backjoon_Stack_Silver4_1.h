#pragma once
#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();

		int num = q.front();
		q.pop();

		q.push(num);
	}

	cout << q.front();
}