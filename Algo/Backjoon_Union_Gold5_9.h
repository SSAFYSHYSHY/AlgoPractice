#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int parent[200001], cnt = 0;
std::map<string, int> arr;

int Calc(string s) {
	if (arr.count(s)) return arr[s];
	arr[s] = ++cnt;
	parent[cnt] = cnt;
	return cnt;
}

int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= 200000; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		string a, b, c;
		cin >> a >> b >> c;

		int A = Calc(a);
		int C = Calc(c);

		Union(A, C);
	}

	int m;
	cin >> m;

	while (m--) {
		string x, y;
		cin >> x >> y;

		if (!arr.count(x) || !arr.count(y)) {
			cout << "Not Related\n";
			continue;
		}

		int X = Find(arr[x]);
		int Y = Find(arr[y]);

		if (X == Y) cout << "Related\n";
		else cout << "Not Related\n";
	}


}