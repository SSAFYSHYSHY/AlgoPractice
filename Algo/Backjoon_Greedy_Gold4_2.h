#pragma once
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> pq2;
int n, sum = 0, cnt = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num > 0) {
			pq.push(num);
		}
		else if (num == 0) {
			cnt++;
		}
		else {
			pq2.push(num);
		}
	}

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();

		if (now > 1 && !pq.empty() && pq.top() > 1) {
			sum += now * pq.top();
			pq.pop();
		}
		else {
			sum += now;
		}
	}
	while (!pq2.empty()) {
		int now = pq2.top();
		pq2.pop();

		if (!pq2.empty()) {
			sum += now * pq2.top();
			pq2.pop();
		}
		else if (!cnt) {
			sum += now;
		}
	}

	cout << sum;
}