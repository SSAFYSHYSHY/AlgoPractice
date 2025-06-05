#pragma once
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int arr[] = { 4,1,2 };

    while (n > 0) {
        answer = to_string(arr[n % 3]) + answer;
        if (n % 3 == 0) n--;
        n /= 3;
    }

    return answer;
}