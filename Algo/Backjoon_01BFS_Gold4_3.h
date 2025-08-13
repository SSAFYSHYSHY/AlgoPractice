#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

int n, a, b, ans = 0;
int dist[101];
vector<int> v[101];

void Input() {
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;

			v[i].push_back(x);
		}
		dist[i] = INT_MAX;
	}
}

void BFS() {
	deque<int> q;
	q.push_front(a);
	dist[a] = 0;

	while (!q.empty()) {
		int cx = q.front();
		q.pop_front();

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i];

			int cost = (i == 0 ? 0 : 1);

			if (dist[nx] > dist[cx] + cost) {
				dist[nx] = dist[cx] + cost;

				if (cost == 0) {
					q.push_front(nx);
				}
				else {
					q.push_back(nx);
				}
			}

		}


	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	BFS();

	if (dist[b] == INT_MAX) {
		cout << -1;
	}
	else {
		cout << dist[b];
	}
}