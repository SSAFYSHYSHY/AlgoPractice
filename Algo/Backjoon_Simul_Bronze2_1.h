#pragma once
#include <iostream>
#include <string>

using namespace std;

int arr[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
int ans = 0;

int main() {
	string s;
	cin >> s;

	for (int i = 0; s[i] != NULL; i++) {

		ans += arr[s[i] - 'A'];

	}

	cout << ans;
}