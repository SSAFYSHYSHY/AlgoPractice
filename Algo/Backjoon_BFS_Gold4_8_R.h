#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
struct Node {
	string a, b;
	float cost;
};

unordered_map<string, bool> visited;
vector<Node> v;

void Calc(string s) {
	string num, num2;
	string a, b;
	bool flag = false;

	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9' && !flag) {
			num += s[i];
		}
		else if ('A' <= s[i] && s[i] <= 'Z' && !flag) {
			a += s[i];
		}
		else if ('a' <= s[i] && s[i] <= 'z' && !flag) {
			a += s[i];
		}

		if (s[i] == '=') flag = true;

		if ('0' <= s[i] && s[i] <= '9' && flag) {
			num2 += s[i];
		}
		else if ('A' <= s[i] && s[i] <= 'Z' && flag) {
			b += s[i];
		}
		else if ('a' <= s[i] && s[i] <= 'z' && flag) {
			b += s[i];
		}
	}

	float num_a, num_b;
	num_a = stoi(num);
	num_b = stoi(num2);

	v.push_back({ a,b , (float)(num_a / num_b) });
	v.push_back({ b,a , (float)(num_b / num_a) });
}

void BFS(string s, float num) {
	queue<pair<string, float>> q;
	q.push({ s, num });
	visited[s] = true;

	while (!q.empty()) {
		string cur = q.front().first;
		float cnum = q.front().second;
		q.pop();

		for (auto& edge : v) {
			if (edge.a == cur && !visited[edge.b]) {
				visited[edge.b] = true;
				float nnum = cnum * edge.cost;
				q.push({ edge.b, nnum });
			}
			else if (edge.b == cur && !visited[edge.a]) {
				visited[edge.a] = true;
				float nnum = cnum / edge.cost;
				q.push({ edge.a, nnum });
			}

		}

	}

}

void Calc2(string s) {
	string tar, tar2;

	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') tar2 += s[i];
		else if ('A' <= s[i] && s[i] <= 'Z') {
			tar += s[i];
		}
		else if ('a' <= s[i] && s[i] <= 'z') {
			tar += s[i];
		}
	}

	int num = stoi(tar2);

	for (int i = 0; i < v.size(); i++) {
		BFS(tar, num);
	}
}

int main() {

	int cnt = 1;

	while (1) {
		visited.clear();
		v.clear();

		cin >> n;

		if (n == 0) break;

		cin.ignore();

		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);

			Calc(s);
		}

		string s;
		getline(cin, s);

		Calc2(s);

		cout << "Case " << cnt << ": " << ;
		cnt++;
	}



}