#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

bool visited[24][60];
int sh, sm, th, tm;

int Calc(const string& s) {
	return stoi(s.substr(0, 2));
}

int Calc2(const string& s) {
	return stoi(s.substr(3, 2));
}

struct Node {
	int x, y, cnt;
};

void BFS() {
	queue<Node> q;
	q.push({ sh,sm,0 });
	visited[sh][sm] = true;

	while (!q.empty()) {
		int h = q.front().x;
		int m = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (h == th && m == tm) {
			cout << ccnt << "\n";
			return;
		}

		int nh = h, nm = (m + 1) % 60;
		if (m == 59) nh = (h + 1) % 24;
		if (!visited[nh][nm]) {
			visited[nh][nm] = true;
			q.push({ nh,nm,ccnt + 1 });
		}

		nh = (h + 1) % 24, nm = m;
		if (!visited[nh][nm]) {
			visited[nh][nm] = true;
			q.push({ nh, nm, ccnt + 1 });
		}
	}
}

int main() {
	string start, tar;
	cin >> start >> tar;

	sh = Calc(start), sm = Calc2(start);
	th = Calc(tar), tm = Calc2(tar);

	memset(visited, false, sizeof(visited));

	BFS();
}