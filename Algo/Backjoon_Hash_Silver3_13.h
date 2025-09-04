#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long a, b, c;
unordered_map<string, long long> ma, mb;
unordered_set<string> mc;

long long n;

void Input() {
	cin >> a >> b >> c;

	for (long long i = 0; i < a; i++) {
		string s;
		long long num;
		cin >> s >> num;

		ma.insert({ s, num });
	}

	for (long long i = 0; i < b; i++) {
		string s;
		long long num;
		cin >> s >> num;

		mb.insert({ s, num });
	}

	for (long long i = 0; i < c; i++) {
		string s;

		cin >> s;

		mc.insert({ s });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	cin >> n;

	long long f_a = 0, s_a = 0, cnt = 0;
	for (long long i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (ma.find(s) != ma.end()) {
			f_a += ma[s];
		}
		else if (mb.find(s) != mb.end()) {
			s_a += mb[s];
		}
		else if (mc.find(s) != mc.end()) {
			cnt++;
		}
	}

	if (cnt > 1) {
		cout << "No";
		return 0;
	}

	if (cnt == 1) {
		if (f_a >= 20000 && f_a + s_a >= 50000) cout << "Okay";
		else cout << "No";
	}
	else {
		if (s_a > 0 && f_a < 20000) cout << "No";
		else cout << "Okay";
	}
}
