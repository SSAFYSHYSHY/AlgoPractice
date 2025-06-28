#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, ans = 100001;

int main() {
	cin >> a >> b;

	ans = min(a, b);

	cout << ans;
}