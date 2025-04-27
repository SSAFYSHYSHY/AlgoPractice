#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Cow {
    int lapTime;
    vector<int> nextCows;
};

int main() {
    int n;
    cin >> n;

    vector<Cow> cows(n + 1); // �� ��ȣ�� 1������
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> cows[i].lapTime >> m;
        for (int j = 0; j < m; ++j) {
            int next;
            cin >> next;
            cows[i].nextCows.push_back(next);
        }
    }

    vector<int> startTime(n + 1, INT_MAX); // �Ұ� �����ϴ� �ð�
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    startTime[1] = 0;
    pq.push(make_pair(0, 1)); // (���۽ð�, �ҹ�ȣ)

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int curStart = top.first;
        int cowNum = top.second;

        int finishTime = curStart + cows[cowNum].lapTime;

        for (int i = 0; i < cows[cowNum].nextCows.size(); ++i) {
            int nextCow = cows[cowNum].nextCows[i];

            if (startTime[nextCow] > finishTime) {
                startTime[nextCow] = finishTime;
                pq.push(make_pair(startTime[nextCow], nextCow));
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result = max(result, startTime[i] + cows[i].lapTime);
    }

    cout << result << endl;
    return 0;
}