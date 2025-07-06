#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, boss;
vector<int> v[100001];
bool visited[100001];
int score[100001];

void Input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		//해당 보스에서부터 자식 까지 내려가 각각 점수를 누적해야 한다.
		if (num == -1) boss = i;
		else {
			v[num].push_back(i);
		}
	}

	for (int i = 0; i < m; i++) {
		int idx, num;
		cin >> idx >> num;

		score[idx] += num;
	}
}

void DFS(int start) {
	visited[start] = true;

	for (int next : v[start]) {
		if (!visited[next]) {
			score[next] += score[start];
			DFS(next);
		}
	}
}

int main() {
	Input();

	//DFS로 시작.
	DFS(boss);

	for (int i = 1; i <= n; i++) {
		cout << score[i] << " ";
	}
}
