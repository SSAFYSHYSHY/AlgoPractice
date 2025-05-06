#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t;
long long arr[100001];
long long prefix[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(prefix, 0, sizeof(prefix));
		int n, q;
		cin >> n >> q;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			prefix[i] = prefix[i - 1] + arr[i];
		}

		for (int i = 0; i < q; i++) {
			int s, e;
			cin >> s >> e;
			s++;
			e++;

			cout << prefix[e] - prefix[s - 1] << "\n";
		}

		cout << "\n";
	}
}