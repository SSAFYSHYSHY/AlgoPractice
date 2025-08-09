#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[1000001];
long long brr[1000001];
long long prefixa[1000001];
long long prefixb[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (long long i = 1; i <= m; i++) {
		cin >> brr[i];
	}

	prefixa[0] = 0;
	prefixb[0] = 0;
	for (long long i = 1; i <= n; i++) {
		prefixa[i] = prefixa[i - 1] + arr[i];
	}

	for (long long i = 1; i <= m; i++) {
		prefixb[i] = prefixb[i - 1] + brr[i];
	}

	long long i = 1, j = 1, ans = n + m;
	while (i <= n && j <= m) {
		//같은 누적합인 경우에는 갱신.
		if (prefixa[i] == prefixb[j]) {
			long long num = (n - i) + (m - j);

			if (num < ans) {
				ans = num;
			}
			i++;
			j++;
		}
		else if (prefixa[i] > prefixb[j]) {
			j++;
		}
		else {
			i++;
		}

	}

	cout << ans;
}