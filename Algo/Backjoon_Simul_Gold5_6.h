#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[10000][6], ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][4] >> arr[i][5] >> arr[i][3];
	}

	for (int i = 0; i < 6; i++) {
		int tar = i, cnt = 0;
		int res = 0;

		while (cnt < N) {
			int now_num = 0;
			for (int j = 0; j < 6; j++) {
				if ((j != tar && j != (tar + 3) % 6) && now_num < arr[cnt][j])
					now_num = arr[cnt][j];
			}
			res += now_num;

			if (cnt < N - 1) {
				int num = arr[cnt][(tar + 3) % 6];

				for (int j = 0; j < 6; j++) {
					if (num == arr[cnt + 1][j]) {
						tar = j;
						break;
					}
				}
			}
			cnt++;
		}

		ans = max(ans, res);
	}

	cout << ans;

	return 0;
}