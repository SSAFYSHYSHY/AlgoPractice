#pragma once
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	while (1) {
		int n;
		cin >> n;

		if (n == 0) break;

		string s;
		unordered_set<char> set;
		cin >> s;

		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			//���� �������� ������.
			if (set.find(s[i]) == set.end()) {

				//���� n ���� ������. cnt++
				if (set.size() >= n) {
					cnt++;
				}
				//���� n ���� ������ �ֱ�. 
				else {
					set.insert(s[i]);
				}
			}
			//�Ȱ��� �� �߽߰�.
			else {
				set.erase(s[i]);
			}
		}

		if (cnt == 0) {
			cout << "All customers tanned successfully.\n";
		}
		else {
			cout << cnt / 2 << " customer(s) walked away.\n";
		}
	}

}