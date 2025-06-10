#pragma once
#include <iostream>
#include <unordered_map> 
#include <algorithm>
#include <vector>

using namespace std;

long long n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n--) {
		unordered_map<long long, long long> map;

		long long num;
		cin >> num;

		long long ans_cnt = num / 2;
		for (long long i = 0; i < num; i++) {
			long long a;
			cin >> a;

			map[a]++;
		}

		long long max_number = 0, max_cnt = 0;
		bool flag = false;
		for (auto& p : map) {
			long long number = p.first;
			long long cnt = p.second;

			if (cnt > max_cnt) {
				max_cnt = cnt;
				max_number = number;
				flag = false;
			}
			else if (cnt == max_cnt) {
				flag = true;
			}

		}

		if (max_cnt > ans_cnt && !flag) {
			cout << max_number << "\n";
		}
		else {
			cout << "SYJKGW" << "\n";
		}


	}

}