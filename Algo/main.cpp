#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long n, k, ans = 0;
long long arr[200001];
long long prefix[200001];

int main() {
	cin >> n >> k;

	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];

		prefix[i] = prefix[i - 1] + arr[i];
	}

	map<long long, long long> m;
	for (long long i = 0; i < n + 1; i++) {
		ans += m[prefix[i] - k];
		m[prefix[i]]++;
	}
	cout << ans;
}