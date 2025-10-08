#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
    vector<pair<double, double>> logs; // (시작시간, 끝시간)

    for (auto& line : lines) {
        int h = stoi(line.substr(11, 2));
        int m = stoi(line.substr(14, 2));
        double s = stod(line.substr(17, 6)); // 초 단위(소수점 포함)
        double t = stod(line.substr(24, line.size() - 25)); // 처리시간 (s 제거)

        double end = h * 3600 + m * 60 + s;
        double start = end - t + 0.001; // 처리시간 포함 (끝점과 시작점 모두 포함)
        logs.push_back({ start, end });
    }

    int answer = 0;
    for (int i = 0; i < logs.size(); i++) {
        double start_window = logs[i].first;
        double end_window = logs[i].second;

        // 각 로그의 끝 시각 기준으로 1초 구간 검사
        double window_start = end_window;
        double window_end = end_window + 0.999; // [end, end+1초)

        int cnt = 0;
        for (auto& log : logs)
            if (!(log.second < window_start || log.first > window_end))
                cnt++;
        answer = max(answer, cnt);
    }
    return answer;
}
