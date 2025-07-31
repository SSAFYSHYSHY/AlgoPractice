
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 987654321;
int people_num, relation_num;
vector<vector<int>> dist;
bool visited[101], is_in_que[101];
int committee_order = 0;
vector<vector<int>> committee_member;

void FindCommitteeBFS(int start_idx) {
    queue<int> q;
    vector<int> new_committee;
    new_committee.push_back(start_idx);

    q.push(start_idx);
    is_in_que[start_idx] = true;
    visited[start_idx] = true;

    int idx;
    while (!q.empty()) {
        idx = q.front();
        q.pop();
        visited[idx] = true;

        for (int i = 1; i <= people_num; ++i) {
            if (!visited[i] && !is_in_que[i])
                if (dist[idx][i] < INF) {
                    q.push(i);
                    is_in_que[i] = true;
                    new_committee.push_back(i);
                }

        }
    }

    committee_member.push_back(new_committee);
}

void FloydWarshall() {
    for (int k = 1; k <= people_num; ++k)
        for (int i = 1; i <= people_num; ++i)
            for (int j = 1; j <= people_num; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> people_num >> relation_num;

    dist = vector<vector<int>>(people_num + 1, vector<int>(people_num + 1, INF));
    for (int i = 1; i <= people_num; ++i)
        dist[i][i] = 0;

    int u, v;
    for (int i = 0; i < relation_num; ++i) {
        cin >> u >> v;
        dist[u][v] = dist[v][u] = 1;
    }

    FloydWarshall();

    memset(visited, false, sizeof(visited));
    memset(is_in_que, false, sizeof(is_in_que));

    for (int i = 1; i <= people_num; ++i)
        if (!visited[i]) {
            FindCommitteeBFS(i);
            ++committee_order;
        }

    vector<int> representives;
    int now_idx, next_idx;
    for (int k = 0; k < committee_order; ++k) {
        pair<int, int> represent_info(0, INF);

        for (int i = 0; i < committee_member[k].size(); ++i) {
            int max_dist = 0;
            now_idx = committee_member[k][i];

            for (int j = 0; j < committee_member[k].size(); ++j) {
                next_idx = committee_member[k][j];
                max_dist = max(dist[now_idx][next_idx], max_dist);
            }

            if (max_dist < represent_info.second)
                represent_info = { now_idx, max_dist };
        }
        representives.push_back(represent_info.first);
    }

    sort(representives.begin(), representives.end());

    cout << committee_order << "\n";
    for (int i = 0; i < representives.size(); ++i)
        cout << representives[i] << "\n";

    return 0;
}#pragma once
