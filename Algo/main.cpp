#include <iostream>

using namespace std;

int arr[200001];

int main() {
	int sum = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			sum -= 1;
		}
		else {
			sum += 1;
		}

		arr[i] = sum;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}

	cout << ans;

}