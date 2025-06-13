#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int arr[226];

int main() {
	int n;
	cin >> n;
	memset(arr, 0, sizeof(arr));

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
	}

	int max_cnt = 0;
	for (int i = 0; i < 226; i++) {
		max_cnt = max(max_cnt, arr[i]);
	}

	cout << s.length() - max_cnt;
}