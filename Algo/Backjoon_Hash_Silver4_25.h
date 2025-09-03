#pragma once
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<int> seta, setb, setc;
int t;

//5 와 8만 들어가 있어야 함.
bool Calc(string s) {

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '5' && s[i] != '8') {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a;

		for (int i = 0; i < a; i++) {
			int num;
			cin >> num;

			seta.insert(num);
		}

		cin >> b;
		for (int i = 0; i < b; i++) {
			int num;
			cin >> num;

			setb.insert(num);
		}

		cin >> c;
		for (int i = 0; i < c; i++) {
			int num;
			cin >> num;

			setc.insert(num);
		}

		unordered_set<int> ans;
		for (auto i : seta) {
			for (auto j : setb) {
				for (auto k : setc) {
					int sum = i + j + k;

					string s = to_string(sum);

					//체크.
					if (Calc(s)) {
						ans.insert(stoi(s));
					}
				}
			}
		}

		cout << ans.size() << "\n";

		seta.clear();
		setb.clear();
		setc.clear();
	}

}