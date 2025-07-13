#pragma once
#include <string>
#include <vector>
#define MAX 100000000000000

using namespace std;
vector<int> diff, curr_time;
long long limits;

bool Calc(long long now) {
    long long total = 0;

    for (int i = 0; i < diff.size(); i++) {
        if (diff[i] <= now) {
            total += curr_time[i];
        }
        else {
            total += (curr_time[i] + curr_time[i - 1]) * (diff[i] - now) + curr_time[i];
        }
    }

    if (total <= limits) {
        return true;
    }

    return false;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long answer = 0;
    diff = diffs;
    curr_time = times;
    limits = limit;

    long long l = 1;
    long long r = MAX;

    while (l <= r) {
        long long mid = (l + r) / 2;

        if (Calc(mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return answer;
}