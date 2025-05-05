#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dist(N + 1);       // dist[1] = m1, ..., dist[N] = mN
    vector<int> prefix(N + 1);     // prefix[i] = 창고 -> i번 도시까지 걸리는 시간

    for (int i = 1; i <= N; ++i) {
        cin >> dist[i];
        prefix[i] = prefix[i - 1] + dist[i];
    }

    int K;
    cin >> K;

    bool possible = true;
    int maxCity = 0;  // 가장 멀리 있는 배달 도시
    for (int i = 0; i < K; ++i) {
        int a, t;  // 도시 번호, 마감 시간
        cin >> a >> t;

        int arrivalTime = prefix[a];  // 창고 → a번 도시까지의 시간

        if (arrivalTime > t) {
            possible = false;  // 배달 불가능
        }

        maxCity = max(maxCity, a);  // 가장 멀리 있는 도시 기억
    }

    if (!possible) {
        cout << -1 << "\n";
    }
    else {
        // 가장 멀리 간 후, 다시 창고로 돌아옴: 왕복 시간 = 2 * prefix[maxCity]
        cout << 2 * prefix[maxCity] << "\n";
    }

    return 0;
}
