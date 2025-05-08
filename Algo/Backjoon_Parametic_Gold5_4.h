#pragma once
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int l = 1, r = n;

	while (l <= r) {
		int x;
		int mid = (l + r) / 2;

		cout << "? " << mid << "\n";
		cin >> x;

		if (mid % 2 == 0 && x == mid / 2) {
			cout << "! " << mid << "\n";
			return 0;
		}

		//���� ���뺸�� ������.
		else if (x > mid / 2) {
			l = mid;
		}
		//�ƴϸ�.
		else {
			r = mid;
		}
	}

	cout << "! " << l << "\n";
}