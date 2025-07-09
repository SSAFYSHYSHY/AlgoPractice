#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int arr[4];

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 4);

	int sum = (arr[3] * arr[2]) + (arr[1] * arr[0]);
	cout << sum;

}