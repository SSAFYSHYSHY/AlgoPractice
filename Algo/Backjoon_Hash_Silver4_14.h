#pragma once
#include <iostream>
#include <map>

using namespace std;

int n;
string s;
char c;
map<string, int> arr, ans;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> c;

		if (c == '+') {
			arr[s] += 1;
		}
		else {
			if (arr[s] <= 0) {
				ans[s] += 1;
			}
			else {
				arr[s] -= 1;
			}
		}
	}

	int res = 0;
	for (auto it = arr.begin(); it != arr.end(); it++) {
		res += it->second;
		res += ans[it->first];
	}

	cout << res;
}