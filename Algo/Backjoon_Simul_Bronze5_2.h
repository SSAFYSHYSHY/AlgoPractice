#pragma once
#include <iostream>

using namespace std;

char arr[3] = { 'S','U','O' };

int main() {
	int n;
	cin >> n;

	n %= 3;

	cout << arr[n];
}