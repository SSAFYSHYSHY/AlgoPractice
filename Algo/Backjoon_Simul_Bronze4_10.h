#pragma once
#include <iostream>

using namespace std;

string s[] = { "Poblano", "Mirasol", "Serrano", "Cayenne", "Thai", "Habanero" };
int arr[] = { 1500, 6000, 15500, 40000, 75000, 125000 };
int n;

int main() {
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		string name;

		cin >> name;

		for (int j = 0; j < 6; j++) {
			if (s[j] == name) {
				ans += arr[j];
			}
		}

	}

	cout << ans;
}