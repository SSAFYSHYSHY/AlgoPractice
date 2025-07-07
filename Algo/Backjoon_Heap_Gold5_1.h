#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	pq.push(v[0].second);
	for (int i = 1; i < v.size(); i++) {
		//������ ���� ������ pq.top()���� ū �ð�����.
		if (v[i].first >= pq.top()) {
			pq.pop();
			pq.push(v[i].second);
		}
		//�׷��� �ʴٸ� �ش� v.second�� �� ����.
		else {
			pq.push(v[i].second);
		}
	}

	cout << pq.size();

}