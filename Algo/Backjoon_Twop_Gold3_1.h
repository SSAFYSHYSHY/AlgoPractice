#pragma once
#include <iostream>
#include <vector>
#define MAX 4000000

using namespace std;

vector<int> v;
int n;
bool isprime[MAX + 1];

void Make_Prime(int num) {
	fill(isprime, isprime + num + 1, true);
	isprime[0] = isprime[1] = false;

	for (int i = 2; i * i <= num; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= num; j += i) {
				isprime[j] = false;
			}
		}
	}

	for (int i = 2; i <= num; i++) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}
}

int main() {
	cin >> n;

	Make_Prime(n);

	int l = 0, r = 0;
	int sum = 0, ans = 0;

	while (true) {
		if (sum >= n) sum -= v[l++];
		else if (r == v.size()) break;
		else sum += v[r++];

		if (sum == n) ans++;
	}

	cout << ans;
}
