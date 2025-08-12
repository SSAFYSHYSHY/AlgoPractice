#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int Calc1(string s, string s2) {
	if (s.size() != s2.size()) return s.size() < s2.size() ? -1 : 1;
	if (s == s2) return 0;
	return s < s2 ? -1 : 1;
}

string Calc2(string a, string b) {
	string res;
	int carry = 0;

	int n = max(a.size(), b.size());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size() < n) a.push_back('0');
	while (b.size() < n) b.push_back('0');

	for (int i = 0; i < n; i++) {
		int num = (a[i] - '0') + (b[i] - '0') + carry;
		res.push_back(num % 10 + '0');
		carry = num / 10;
	}

	if (carry) {
		res.push_back(carry + '0');
	}
	reverse(res.begin(), res.end());

	return res;
}

string Calc3(string a) {
	string res;
	int carry = 0;
	for (char c : a) {
		int curr = carry * 10 + (c - '0');
		res.push_back(curr / 2 + '0');
		carry = curr % 2;
	}
	int pos = res.find_first_not_of('0');

	return pos == string::npos ? "0" : res.substr(pos);
}

string Calc4(string mid) {
	string a, b;
	a = mid, b = mid;

	vector<int> res(a.size() + b.size());
	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = b.size() - 1; j >= 0; j--) {
			int mul = (a[i] - '0') * (b[j] - '0');
			int sum = mul + res[i + j + 1];

			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}

	string s;
	for (int x : res) {
		if (!(s.empty() && x == 0)) s.push_back(x + '0');
	}
	return s.empty() ? "0" : s;
}

string Calc5(string a) {
	int carry = 1;

	for (int i = a.size() - 1; i >= 0 && carry; i--) {
		int sum = (a[i] - '0') + carry;
		a[i] = sum % 10 + '0';
		carry = sum / 10;
	}

	if (carry) {
		a.insert(a.begin(), '1');
	}
	return a;
}

string Calc6(string mid) {
	string a = mid;
	int i = a.size() - 1;
	while (i >= 0) {
		if (a[i] > '0') {
			a[i]--;
			break;
		}
		a[i] = '9';
		i--;
	}

	if (a[0] == '0' && a.size() > 1) {
		a = a.substr(1);
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	string l = "0", r = s, ans = "0";

	while (Calc1(l, r) <= 0) {
		//´õÇÏ°í , ³ª´®.
		string mid = Calc3(Calc2(l, r));
		//Á¦°ö.
		string num = Calc4(mid);

		int curr = Calc1(num, s);
		if (curr == 0) {
			ans = mid;
			break;
		}
		else if (curr < 0) {
			ans = mid;
			//+1 ´õÇÏ°í.
			l = Calc5(mid);
		}
		else if (curr > 0) {
			//-1 »©°í.
			r = Calc6(mid);
		}
	}

	cout << ans;
}