#pragma once

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int N, M, result;
    int card;
    set<int> s;
    vector<int> v;

    //input & algorithm
    M = result = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &card);

        M += card;
        v.push_back(card);
        for (int num : s)
            v.push_back(card + num);
        s.insert(v.begin(), v.end());
        v.clear();
    }

    //result & output
    result = M - s.size();
    printf("%d\n", result);
    return (0);
}
