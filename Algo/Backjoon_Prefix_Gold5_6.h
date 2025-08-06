#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
int arr[1000001];
int prefix[1000001];

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		arr[s]++;
		arr[e + 1]--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	cin >> q;

	for (int i = 1; i < 1000001; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;

		cout << prefix[num] << "\n";
	}
}