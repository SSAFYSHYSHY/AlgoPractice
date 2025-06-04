#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
unordered_map<string, int> map;
unordered_map<int, string> map2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		map[s] = i;
		map2[i] = s;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if ('0' <= s[0] && s[0] <= '9') {
			int num = stoi(s);

			//�ش� ��ȣ�� string ���.
			cout << map2[num] << "\n";
		}
		else {
			//�ش� ������ ��ȣ ���.
			cout << map[s] << "\n";
		}
	}
}