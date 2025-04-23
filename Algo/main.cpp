#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
bool visited[1001] = {false,};
int arr[1001];

void Back(int s, int e) {
	if (s == e) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			Back(s + 1, e);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	Back(0, 3);
}