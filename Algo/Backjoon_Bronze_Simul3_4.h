#pragma once
#include <iostream>

using namespace std;

int main() {

	int N; cin >> N;

	cout << "int a;\n";
	cout << "int *ptr = &a; \n";

	for (int i = 2; i <= N; i++) {
		cout << "int ";

		for (int k = 0; k < i; k++)
			cout << '*';

		if (i > 2) cout << "ptr" << i << " = &ptr" << i - 1 << ";\n";
		else cout << "ptr" << i << " = &ptr" << ";\n";
	}
}