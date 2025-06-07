#include <iostream>
#include <algorithm>

using namespace std;

int arr[3], brr[3];

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++) {
		cin >> brr[i];
	}

	sort(arr, arr + 3, greater<int>());
	sort(brr, brr + 3, greater<int>());

	long long sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += arr[i] * brr[i];
	}

	cout << sum;
}
