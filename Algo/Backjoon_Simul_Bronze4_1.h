#pragma once
#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n <= 100000) {
		if (n % 2024 == 0) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
	}
	else {
		cout << "No";
	}
}