#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i = 0, j = 0;

    for (string& word : goal) {
        if (i < cards1.size() && cards1[i] == word) {
            i++;
        }
        else if (j < cards2.size() && cards2[j] == word) {
            j++;
        }
        else {
            return "No";
        }
    }

    return "Yes";
}
