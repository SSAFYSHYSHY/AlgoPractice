#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return min(100 - a.first, a.second) < min(100 - b.first, b.second);
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v(m);

	for (int i = 0; i < m; i++) cin >> v[i].first;
	for (int i = 0; i < m; i++) cin >> v[i].second;

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (auto& i : v) pq.push(i);

	int ans = 0;
	for (int i = 0; i < 24 * n; i++)
	{
		if (pq.empty())
			break;

		auto now = pq.top();
		pq.pop();

		now.first = min(100, now.first + now.second);

		if (now.first == 100)
		{
			ans += 100;
			continue;
		}

		pq.push(now);
	}

	while (!pq.empty())
	{
		ans += pq.top().first;
		pq.pop();
	}

	cout << ans << '\n';
	return 0;
}