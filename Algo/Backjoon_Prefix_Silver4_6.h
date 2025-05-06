#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2000002

using namespace std;

long long prefix[MAX];
long long arr[MAX];
char c[MAX];

int main() {
	string s;
	cin >> s;

	//���丷 ��ŭ �ٽ� �־ ������ ��ȯ �ǰԲ�.
	int len = s.length() / 2;

	for (int i = 0; i < len; i++) {
		s.push_back(s[i]);
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'B') arr[i + 1] = 1;
		else {
			arr[i + 1] = 0;
		}
	}

	//B�� ���� ��ŭ ������.
	for (int i = 1; i <= s.length(); i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	//len ��ŭ ������ prefix���� ��.
	long long ans = 0;
	for (int i = 1; i + len - 1 <= s.length(); i++) {
		ans = max(ans, prefix[i + len - 1] - prefix[i - 1]);
	}

	cout << ans;


}