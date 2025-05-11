#pragma once
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n;

// 만들어진 색 조합 저장
vector<vector<int>> vec;

// 물감의 색 저장
vector<vector<int>> paints;

// 배열의 각 원소 사용 유무
vector<bool> visited;

// 곰두리색 저장
vector<int> origin(3);

int ans = INT_MAX;

void check(int cur)
{
    vector<int> temp = vector<int>{ 0 ,0 ,0 };

    for (int i = 0; i < cur; i++)
    {
        temp[0] += vec[i][0];
        temp[1] += vec[i][1];
        temp[2] += vec[i][2];
    }

    int gap = 0;
    for (int i = 0; i < 3; i++)
    {
        gap += abs((temp[i] / cur) - origin[i]);
    }

    // 가장 적은 값을 ans로 저장한다.
    ans = min(ans, gap);
}

void recur(int cur, int start)
{
    // 색을 2가지 이상 섞었다면 곰두리색과 비교
    if (cur >= 2) check(cur);

    // 최대 7색 이상 섞을 수 없다.
    if (cur == 7) return;

    // 중복이 없도록 start를 사용
    for (int i = start + 1; i < n; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;
        vec[cur] = paints[i];
        recur(cur + 1, i);
        visited[i] = false;
    }
}



int main()
{
    cin >> n;

    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        paints.push_back(vector<int>{ a, b, c });
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> origin[i];
    }

    vec.resize(n);
    visited.resize(n, false);

    recur(0, -1);

    cout << ans;

    return 0;
}