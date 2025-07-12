#pragma once
#include <iostream>

using namespace std;

int n;
int m = 24288;

int main() {
	cin >> n;
	m += n * 7;

	cout << m / 12 << " " << (m % 12) + 1;


}