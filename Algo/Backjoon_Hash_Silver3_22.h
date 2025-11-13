#pragma once
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	map<int, long long> m;
	int N;
	int X, T, C;
	map<int, long long>::iterator it;
	long long answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> T >> C;
		it = m.find(T - X);
		if (it == m.end()) {
			m.insert({ T - X, C });
			answer = max(answer, (long long)C);
		}
		else {
			it->second += C;
			answer = max(answer, it->second);
		}
	}

	cout << answer << "\n";
	return 0;
}