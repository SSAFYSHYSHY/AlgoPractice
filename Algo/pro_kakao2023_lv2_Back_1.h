#pragma once
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

double dx[] = { 0.1, 0.2, 0.3, 0.4 };
vector<int> v;

vector<int> copy_v;
vector<vector<int>> copy_user;

vector<int> answer;
vector<pair<int, int>> result;

pair<int, int> Calc(vector<int>& v) {
    vector<int> temp_v;
    for (int i = 0; i < copy_v.size(); i++) {
        int new_price = copy_v[i] * (100 - (v[i] + 1) * 10) / 100;
        temp_v.push_back(new_price);
    }

    int cnt = 0;
    int total_sum = 0;
    for (int i = 0; i < copy_user.size(); i++) {
        int ratio = copy_user[i][0];
        int price = copy_user[i][1];

        int sum = 0;
        for (int j = 0; j < v.size(); j++) {
            if ((v[j] + 1) * 10 >= ratio) {
                sum += temp_v[j];
            }
        }

        if (sum >= price) {
            cnt++;
        }
        else {
            total_sum += sum;
        }
    }

    return { cnt, total_sum };
}


void Back(int now, int tar) {
    if (now == tar) {
        pair<int, int> new_v = Calc(v);
        result.push_back(new_v);
        return;
    }

    for (int i = 0; i < 4; i++) {
        v.push_back(i);
        Back(now + 1, tar);
        v.pop_back();
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    copy_v = emoticons;
    copy_user = users;

    Back(0, emoticons.size());

    sort(result.begin(), result.end(), cmp);

    answer.push_back(result[0].first);
    answer.push_back(result[0].second);

    return answer;
}