#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> input(12, vector<int>(12));
vector<vector<pair<int, int>>> answer(6);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            cin >> input[i][j];

    answer[0].push_back(make_pair(input[0][1], 1));
    answer[0].push_back(make_pair(input[1][0], 0));

    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < (int)answer[i - 1].size(); j++)
        {
            int first = answer[i - 1][j].first +
                input[answer[i - 1][j].second][i * 2] +
                input[i * 2][i * 2 + 1];

            int second = answer[i - 1][j].first +
                input[answer[i - 1][j].second][i * 2 + 1] +
                input[i * 2 + 1][i * 2];

            answer[i].push_back(make_pair(first, i * 2 + 1));
            answer[i].push_back(make_pair(second, i * 2));
        }
    }

    int real_answer = 0x3f3f3f3f;
    for (pair<int, int> tmp : answer[5])
        if (tmp.first < real_answer)
            real_answer = tmp.first;

    cout << real_answer;
}