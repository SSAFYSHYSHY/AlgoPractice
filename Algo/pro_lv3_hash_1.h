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

    // 1. 장르별 총 재생 수, 장르별 노래 목록 저장
    for (int i = 0; i < genres.size(); ++i) {
        genreTotalPlays[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back({ plays[i], i }); // {재생 수, 고유 번호}
    }

    // 2. 장르를 총 재생 수 기준으로 정렬
    vector<pair<string, int>> sortedGenres(genreTotalPlays.begin(), genreTotalPlays.end());
    sort(sortedGenres.begin(), sortedGenres.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });

    vector<int> answer;

    // 3. 각 장르마다 노래 정렬 후 최대 2곡 수록
    for (auto& g : sortedGenres) {
        string genre = g.first;

        // 재생 수 내림차순, 같으면 고유 번호 오름차순
        sort(genreSongs[genre].begin(), genreSongs[genre].end(), [](auto& a, auto& b) {
            if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
            });

        // 최대 2곡 수록
        for (int i = 0; i < genreSongs[genre].size() && i < 2; ++i) {
            answer.push_back(genreSongs[genre][i].second);
        }
    }

    return answer;
}