#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
    vector<pair<double, double>> logs; // (���۽ð�, ���ð�)

    for (auto& line : lines) {
        int h = stoi(line.substr(11, 2));
        int m = stoi(line.substr(14, 2));
        double s = stod(line.substr(17, 6)); // �� ����(�Ҽ��� ����)
        double t = stod(line.substr(24, line.size() - 25)); // ó���ð� (s ����)

        double end = h * 3600 + m * 60 + s;
        double start = end - t + 0.001; // ó���ð� ���� (������ ������ ��� ����)
        logs.push_back({ start, end });
    }

    int answer = 0;
    for (int i = 0; i < logs.size(); i++) {
        double start_window = logs[i].first;
        double end_window = logs[i].second;

        // �� �α��� �� �ð� �������� 1�� ���� �˻�
        double window_start = end_window;
        double window_end = end_window + 0.999; // [end, end+1��)

        int cnt = 0;
        for (auto& log : logs)
            if (!(log.second < window_start || log.first > window_end))
                cnt++;
        answer = max(answer, cnt);
    }
    return answer;
}
