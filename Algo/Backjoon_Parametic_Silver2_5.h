#pragma once
#include <iostream>
#include <algorithm>
#define MAX 100000000000000LL

using namespace std;

long long n, p;
long long arr[101][3];


bool Calc(long long mid) {
	long long total = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i][0] >= mid) {
			// 모드 1
			total += mid * arr[i][1];
		}
		else {
			// 모드 2
			total += arr[i][1] * arr[i][0] + arr[i][2] * (mid - arr[i][0]);
		}

		// 이미 p를 넘었으면 더 계산 안 해도 됨
		if (total >= p) return true;
	}

	return total >= p;
}

int main() {
	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		int z, a, b;
		cin >> z >> a >> b;

		arr[i][0] = z;
		arr[i][1] = a;
		arr[i][2] = b;
	}

	long long l = 1;
	long long r = MAX;
	long long ans = 0;

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
