#pragma once
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s = "";
	int M, x;
	int arr[21] = { 0 };

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s;

		if (s == "add") {
			cin >> x;
			if (arr[x] == 0) {
				arr[x] = 1;
			}
		}

		else if (s == "remove") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}

		}
		else if (s == "check") {
			cin >> x;
			if (arr[x] == 0) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (s == "toggle") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
			else {
				arr[x] = 1;
			}
		}
		else if (s == "all") {

			for (int k = 1; k <= 20; k++) { arr[k] = 1; }

		}
		else if (s == "empty") {
			memset(arr, 0, sizeof(arr));
		}
	}

	return 0;
}