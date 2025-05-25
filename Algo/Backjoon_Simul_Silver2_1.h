#pragma once
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<int> s;
	string str;

	int cnt = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			cnt += s.size();
			i++;
		}
		else if (str[i] == '(') {
			s.push(i);
		}
		else if (str[i] == ')') {
			cnt++;
			s.pop();
		}
	}
	cout << cnt;
}