#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

long long b, n, m;

unordered_map<string, long long> map;

int main() {
	cin >> b >> n >> m;

	for (long long i = 0; i < n; i++) {
		string s;
		long long a;
		cin >> s >> a;

		map[s] = a;
	}

	long long num = 0;
	for (long long i = 0; i < m; i++) {
		string s;
		cin >> s;

		num += map[s];
	}

	if (num > b) {
		cout << "unacceptable";
	}
	else {
		cout << "acceptable";
	}
}