#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> timePQ;  // T 이벤트
    priority_queue<int, vector<int>, greater<int>> distPQ;  // D 이벤트

    for (int i = 0; i < N; i++) {
        char type;
        int x;
        cin >> type >> x;
        if (type == 'T') timePQ.push(x);
        else distPQ.push(x);
    }

    double t = 0.0;     // 현재까지 걸린 시간
    double d = 0.0;     // 현재까지 이동한 거리
    int slows = 0;      // 지금까지 느려진 횟수 → 속도는 1/(slows+1)

    while (d < 1000) {
        double speed = 1.0 / (slows + 1);

        double t_event = 1e18;
        double d_event = 1e18;

        // 다음 시간 이벤트까지 남은 시간
        if (!timePQ.empty())
            t_event = timePQ.top() - t;

        // 다음 거리 이벤트까지 남은 거리
        if (!distPQ.empty())
            d_event = distPQ.top() - d;

        double timeToDistEvent = d_event / speed;  // 거리 이벤트까지 걸리는 시간

        double actualTime = min(t_event, timeToDistEvent);

        // 이동
        d += actualTime * speed;
        t += actualTime;

        // 이벤트 처리
        bool slowed = false;

        // 시간 이벤트 도달
        if (!timePQ.empty() && abs(t - timePQ.top()) < 1e-9) {
            while (!timePQ.empty() && abs(timePQ.top() - t) < 1e-9) {
                timePQ.pop();
                slows++;
                slowed = true;
            }
        }

        // 거리 이벤트 도달
        if (!distPQ.empty() && abs(d - distPQ.top()) < 1e-9) {
            while (!distPQ.empty() && abs(distPQ.top() - d) < 1e-9) {
                distPQ.pop();
                slows++;
                slowed = true;
            }
        }

        // 이벤트 없이 그냥 이동해서 1000m 도달하면 반복 종료됨
        if (!slowed && d >= 1000) break;
    }

    // 반올림
    long long ans = (long long)llround(t);
    cout << ans << "\n";

    return 0;
}