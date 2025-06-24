#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;

int main() {
	cin >> n >> k;

	long long cnt = (n + k - 1) / k;

	cout << n / cnt << "\n";
}