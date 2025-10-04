#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[20];
string ans[5];
bool visited[20];
int L, N;
bool chk = 0; // 0: 답 출력 안함, 1: 답 출력함

void func(int cnt) {
	if (cnt == L) {
		if (!chk) {
			bool sign = 1;
			for (int i = 0; i < L; i++) {
				for (int j = i + 1; j < L; j++) {
					if (ans[i][j] != ans[j][i]) sign = 0;
				}
			}
			if (sign) {
				chk = 1;
				for (int i = 0; i < L; i++) cout << ans[i] << '\n';
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			ans[cnt] = arr[i];
			func(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	func(0);

	if (!chk) cout << "NONE";
}