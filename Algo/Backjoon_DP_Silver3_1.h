#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

// dp[i]는 i를 제곱수들의 합으로 표현할 때 필요한 최소 개수
int dp[50001] = { 0, };
int n;

int main() {
	cin >> n;  // 입력: 표현할 숫자 n

	dp[0] = 0;  // 0은 아무 제곱수도 필요 없음

	// 1부터 n까지 모든 숫자에 대해 dp 계산
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		// 최악의 경우: 모두 1^2로만 구성 (즉, i개 필요)

		for (int j = 1; j * j <= i; j++) {
			// j^2가 i보다 작거나 같은 모든 제곱수에 대해
			// i를 i - j^2 로 만든 후, 거기에 j^2 하나 더하는 방식
			// 그 결과들 중에서 가장 작은 개수를 dp[i]에 저장
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];  // n을 표현할 때 필요한 최소 제곱수 개수 출력
}