#pragma once
#include <vector>
#include <iostream>

using namespace std;

bool visited[51] = { false, };
int cnt = 0;
vector<int> v;

bool Prime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool Calc() {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    if (Prime(sum)) {
        return true;
    }
    else {
        return false;
    }

}

void Back(int idx, int now, const vector<int> nums) {
    if (now == 3) {
        if (Calc()) {
            cnt++;
        }
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(nums[i]);
            Back(i + 1, now + 1, nums);
            v.pop_back();
            visited[i] = false;
        }
    }
}


int solution(vector<int> nums) {
    int answer = -1;

    Back(0, 0, nums);

    answer = cnt;
    return answer;
}