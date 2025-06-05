#pragma once
#include <string>
#include <vector>

using namespace std;

string arr[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int date[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

string solution(int a, int b) {

    int total_date = 0;
    for (int i = 1; i < a; i++) {
        total_date += date[i];
    }
    total_date += b;

    //하루씩 앞 당김.
    int idx = (total_date + 4) % 7;

    return arr[idx];
}