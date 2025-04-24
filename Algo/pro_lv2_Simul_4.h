#pragma once
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    long long fact[21] = { 1 };
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    k--;
    for (int i = 0; i < n; i++) {
        long long f = fact[n - 1 - i];
        int idx = k / f;
        answer.push_back(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= f;
    }


    return answer;
}