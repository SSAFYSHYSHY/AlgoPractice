#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, K, sum = 0; 
int a, b; 
vector<pair<int, int>> v;

int main()
{
    cin >> N >> L >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        if (K == 0) break; // K가 0이면 종료
        if (L >= v[i].second)
        {
            sum += 140;
            K--;
        }
    }
    // 쉬운 난이도가 L보다 작거나 같고(풀 수 있으면) AND 어려운 난이도가 L보다 크면(풀 수 없으면),100점 적립, K(풀 수 있는 문제 개수) -1
    for (int i = 0; i < N; i++)
    {
        if (K == 0) break; // K가 0이면 종료
        if (L >= v[i].first && L < v[i].second)
        {
            sum += 100;
            K--;
        }
    }

    // 출력
    cout << sum;

    return 0;
}