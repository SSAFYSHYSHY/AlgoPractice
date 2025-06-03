#pragma once
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    double sum = 0;
    double len = arr.size();

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    answer = sum / len;

    return answer;
}