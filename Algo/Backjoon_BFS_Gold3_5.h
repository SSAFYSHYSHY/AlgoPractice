#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, a, b, ans = -1;

//턴 수로 나눈다.
int visited[500001] = { 0, };

bool InRange(int x) {
	return 1 <= x && x <= 500000;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push({ a,0 });
	q.push({ b,0 });

	while (!q.empty()) {
		int pos = q.front().first;
		int day = q.front().second;
		q.pop();

		int dist = 1 << day;

		int npos = pos + dist;
		if (npos <= n) {
			if (visited[npos] == day + 1) {
				ans = day + 1;
				break;
			}
			else {
				visited[npos] = day + 1;
				q.push({ npos, day + 1 });
			}
		}

		npos = pos - dist;
		if (npos > 0) {
			if (visited[npos] == day + 1) {
				ans = day + 1;
				break;
			}
			else {
				visited[npos] = day + 1;
				q.push({ npos, day + 1 });
			}
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));

	cin >> n >> a >> b;

	BFS();

	cout << ans;

}