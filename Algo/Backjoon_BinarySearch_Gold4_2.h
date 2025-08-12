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
	//��� ����
	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		//x���� ���� ����� ���.
		auto it = lower_bound(v.begin(), v.end(), x);
		bool flag = false;

		//���� �ƴ� x �̻��� ��� �ٷ� ����.
		if (it != v.end()) {
			if (abs(*it - x) + y <= l) flag = true;
		}
		//�������� �ƴ� ���� ����� ��ġ ����.
		if (it != v.begin()) {
			it--;
			if (abs(*it - x) + y <= l) flag = true;
		}

		if (flag) cnt++;
	}

	cout << cnt;


}