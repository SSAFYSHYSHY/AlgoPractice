#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct info {
	int k, l, d, h;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.d == b.d) {
			if (a.h == b.h)
				return a.l > b.l;
			return a.h < b.h;
		}
		return a.d < b.d;
	}
};

int N, K, M, d, h;
queue<info> arr[100000];
int cnt = 0;

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> d >> h;

		arr[i % M].push({ i, i % M, d, h });
	}

	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < M; i++) {
		if (!arr[i].empty()) {
			pq.push(arr[i].front());
			arr[i].pop();
		}
	}

	while (cnt < N) {
		info next = pq.top();
		pq.pop();

		if (next.k == K)
			break;
		else {
			if (!arr[next.l].empty()) {
				pq.push(arr[next.l].front());
				arr[next.l].pop();
			}
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}