#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> a;
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		a.insert(num);
	}

	cout << a.size();
}
