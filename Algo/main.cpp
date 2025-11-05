#include <iostream>
#include <algorithm>

using namespace std;

int arr[41][41];
bool visited[41][41] = { false, };
int n, m;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			visited[i][j] = false;
		}
	}

	int sx = 0, sy = 0;
	for (int i = sx; i < n; i++) {
		for (int j = sy; j < m; j++) {
			for (int k = 0; k < 4; k++) {

			}

		}
	}
}