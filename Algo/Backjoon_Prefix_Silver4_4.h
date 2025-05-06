#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[100001];
long long prefix[100001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		prefix[i] = prefix[i - 1] + arr[i];
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int s, e;
		cin >> s >> e;
		s++;
		e++;

		cout << (prefix[e] - prefix[s]) + (prefix[s] - prefix[s - 1]) << "\n";
	}

}