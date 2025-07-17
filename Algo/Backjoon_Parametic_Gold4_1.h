#pragma once
#include <iostream>
#include <algorithm>
#include <climits>

#define MAX LLONG_MAX

using namespace std;

long long arr[123456][3];
long long n, atk, ans = 0;


void Input() {
	cin >> n >> atk;

	for (long long i = 0; i < n; i++) {
		long long num, a, h;
		cin >> num >> a >> h;

		arr[i][0] = num;
		arr[i][1] = a;
		arr[i][2] = h;
	}

}

bool Calc(long long hmax) {
	long long hcur = hmax;
	long long curatk = atk;

	for (int i = 0; i < n; i++) {
		//1�� ��� ���� ���� ����.
		if (arr[i][0] == 1) {

			long long matk = arr[i][1];
			long long mhp = arr[i][2];

			//���� �ϼ� ���.
			long long turn = mhp / curatk;
			if (mhp % curatk != 0) turn++;

			hcur -= matk * (turn - 1);

			if (hcur <= 0) return false;

		}
		//2�� ��� ȸ��.
		else if (arr[i][0] == 2) {
			hcur += arr[i][2];
			curatk += arr[i][1];

			//ü���� �̻����� ������ hmax�� ����.
			if (hcur > hmax) {
				hcur = hmax;
			}
		}
	}

	return true;
}

int main() {
	Input();

	long long l = 1, r = MAX;
	while (l <= r) {
		long long mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
}