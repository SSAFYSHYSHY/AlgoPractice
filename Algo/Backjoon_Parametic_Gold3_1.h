#pragma once
#include <iostream>
#define MAX 2000000000

using namespace std;

int n, k;
int arr[1000000];

bool Calc(int now, int cnt) {

	int sum = 0;
	int curr_cnt = 0;

	for (int i = 0; i < n; i++) {
		//점수를 순서대로 계속 합한다.
		sum += arr[i];

		//그리고 mid 값을 넘으면 cnt 누적, sum 재갱신.
		if (sum >= now) {
			curr_cnt++;
			sum = 0;
		}
	}

	//만약 cnt가 curr_cnt와 같다면 반환.
	return curr_cnt >= k;

}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int l = 1, r = MAX, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid, k)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans;
}