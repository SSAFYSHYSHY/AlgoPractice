#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genreTotalPlays;
    unordered_map<string, vector<pair<int, int>>> genreSongs;

    // 1. �帣�� �� ��� ��, �帣�� �뷡 ��� ����
    for (int i = 0; i < genres.size(); ++i) {
        genreTotalPlays[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back({ plays[i], i }); // {��� ��, ���� ��ȣ}
    }

    // 2. �帣�� �� ��� �� �������� ����
    vector<pair<string, int>> sortedGenres(genreTotalPlays.begin(), genreTotalPlays.end());
    sort(sortedGenres.begin(), sortedGenres.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });

    vector<int> answer;

    // 3. �� �帣���� �뷡 ���� �� �ִ� 2�� ����
    for (auto& g : sortedGenres) {
        string genre = g.first;

        // ��� �� ��������, ������ ���� ��ȣ ��������
        sort(genreSongs[genre].begin(), genreSongs[genre].end(), [](auto& a, auto& b) {
            if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
            });

        // �ִ� 2�� ����
        for (int i = 0; i < genreSongs[genre].size() && i < 2; ++i) {
            answer.push_back(genreSongs[genre][i].second);
        }
    }

    return answer;
}