#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num, x, y;
		cin >> num >> x >> y;

		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());
	pq.push(v[0].second);

	for (int i = 1; i < v.size(); i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}

	cout << pq.size();
}