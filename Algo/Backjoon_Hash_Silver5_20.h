#pragma once
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

//백준 18679번 코드
string arr[2][100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;
	cin >> n;
	char equal;
	for (int i = 0; i < n; i++) {
		cin >> arr[0][i] >> equal >> arr[1][i];
	}
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string st;
			cin >> st;
			for (int k = 0; k < n; k++) {
				if (arr[0][k] == st) {
					cout << arr[1][k];	break;
				}
			}
			cout << " ";
		}
		cout << endl;
	}
}