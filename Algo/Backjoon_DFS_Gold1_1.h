_#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, ans = 0;
int arr[21][21];
int copy_arr[21][21];
int new_arr[21][21];
vector<int> v;

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			copy_arr[i][j] = arr[i][j];
		}
	}
}

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Drop(int idx) {
	memset(new_arr, 0, sizeof(new_arr));

	//위로.
	if (idx == 0) {
		for (int j = 0; j < n; j++) {
			int temp = 0;

			for (int i = 0; i < n; i++) {
				if (arr[i][j] == arr[i + 1][j] && arr[i][j] != 0 && arr[i + 1][j] != 0) {
					new_arr[temp][j] = arr[i][j] + arr[i + 1][j];
					temp++;
					arr[i + 1][j] = 0;
				}

				else if (arr[i][j] != 0) {
					new_arr[temp][j] = arr[i][j];
					temp++;
				}
			}
		}

	}
	//동
	else if (idx == 1) {
		for (int i = 0; i < n; i++) {
			int temp = n - 1;

			for (int j = n - 1; j >= 0; j--) {
				if (arr[i][j] == arr[i][j - 1] && arr[i][j] != 0 && arr[i][j - 1] != 0) {
					new_arr[i][temp] = arr[i][j] + arr[i][j - 1];
					arr[i][j - 1] = 0;
					temp--;
				}

				else if (arr[i][j] != 0) {
					new_arr[i][temp] = 0;
					temp--;
				}
			}
		}

	}

	//아래로
	else if (idx == 2) {
		for (int j = 0; j < n; j++) {
			int temp = n - 1;

			for (int i = n - 1; i >= 0; i--) {
				if (arr[i][j] == arr[i - 1][j] && arr[i][j] != 0 && arr[i - 1][j] != 0) {
					new_arr[temp][j] = arr[i][j] + arr[i - 1][j];
					temp--;
					arr[i - 1][j] = 0;
				}


				else if (arr[i][j] != 0) {
					new_arr[temp][j] = arr[i][j];
					temp--;
				}
			}
		}
	}

	//서로 
	else if (idx == 3) {
		for (int i = 0; i < n; i++) {
			int temp = 0;

			for (int j = 0; j < n; j++) {
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] != 0 && arr[i][j + 1] != 0) {
					new_arr[i][temp] = arr[i][j] + arr[i][j + 1];
					temp++;
					arr[i][j + 1] = 0;
				}

				else if (arr[i][j] != 0) {
					new_arr[i][temp] = arr[i][j];
					temp++;
				}
			}
		}
	}

	//Print();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

int Calc() {
	//초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = copy_arr[i][j];
		}
	}

	//각 벡터 사이즈 별로 회전.
	for (int i = 0; i < v.size(); i++) {
		//중력.

		Drop(v[i]);
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num = max(arr[i][j], num);
		}
	}

	return num;
}

void Back(int now) {
	if (now == 5) {
		ans = max(ans, Calc());
		return;
	}

	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		Back(now + 1);
		v.pop_back();
	}
}

int main() {
	Input();

	Back(0);

	cout << ans;
}