#pragma once
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int>map;

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        map.insert(nums[i]);
    }

    int maxi = nums.size() / 2;
    int mini = map.size();


    answer = min(mini, maxi);

    return answer;
}