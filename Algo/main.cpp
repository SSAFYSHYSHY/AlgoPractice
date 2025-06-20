#include <iostream>
using namespace std;

int N, x, y;
int ans = 4;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> x >> y;
	if (x == 1) ans--;
	if (x == N) ans--;
	if (y == 1) ans--;
	if (y == N) ans--;

	cout << ans;
}