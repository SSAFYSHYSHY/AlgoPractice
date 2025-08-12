#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, l;
vector<int> v;

int main() {
	cin >> n >> m >> l;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);

	}
	//사대 정렬
	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		//x에서 가장 가까운 사대.
		auto it = lower_bound(v.begin(), v.end(), x);
		bool flag = false;

		//끝이 아닌 x 이상의 사대 바로 연산.
		if (it != v.end()) {
			if (abs(*it - x) + y <= l) flag = true;
		}
		//시작점이 아닌 이전 사대의 위치 연산.
		if (it != v.begin()) {
			it--;
			if (abs(*it - x) + y <= l) flag = true;
		}

		if (flag) cnt++;
	}

	cout << cnt;


}