#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int l = 0;
    int r = *max_element(stones.begin(), stones.end());

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        bool flag = false;

        for (auto stone : stones) {
            if (stone - mid < 0) cnt++;
            else cnt = 0;

            if (cnt >= k) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            answer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }

    return answer;
}