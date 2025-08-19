#pragma once
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;

	while (n--) {
		int num, size;
		cin >> num;
		pq.push(num);

		if (pq.size() == pq2.size()) {
			pq.push(num);
		}
		else {
			pq2.push(num);
		}

		if (!pq.empty() && !pq2.empty() && pq.top() > pq2.top()) {
			int a, b;
			a = pq.top();
			b = pq2.top();
			pq.pop();
			pq2.pop();
			pq.push(b);
			pq2.push(a);
		}

		cout << pq.top() << "\n";
	}

}