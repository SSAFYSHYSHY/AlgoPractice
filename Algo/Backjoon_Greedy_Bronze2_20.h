#pragma once
#include <iostream>

using namespace std;

int arr[] = { 25,10,5,1 };
int n;

int main() {
	cin >> n;

	n = 100 - n;

	for (int i = 0; i < 4; i++) {
		cout << n / arr[i] << " ";

		n %= arr[i];
	}
}