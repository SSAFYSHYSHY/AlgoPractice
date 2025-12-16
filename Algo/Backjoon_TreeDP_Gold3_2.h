#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> B, A;
vector<int> seg;

// 세그먼트 트리 초기화
void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = 1; // 아직 사용 안 됨
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

// k번째 (1-indexed) 남아있는 수 찾기
int query(int node, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (seg[node * 2] >= k)
        return query(node * 2, l, mid, k);
    else
        return query(node * 2 + 1, mid + 1, r, k - seg[node * 2]);
}

// 해당 숫자 제거
void update(int node, int l, int r, int idx) {
    if (l == r) {
        seg[node] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx);
    else update(node * 2 + 1, mid + 1, r, idx);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    B.resize(n + 1);
    A.resize(n + 1);
    seg.resize(4 * n);

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        if (B[i] > i - 1) {
            cout << "NIE\n";
            return 0;
        }
    }

    build(1, 1, n);

    // 뒤에서부터 복원
    for (int i = n; i >= 1; i--) {
        int k = seg[1] - B[i]; // (bi+1)번째 큰 수
        if (k <= 0 || k > seg[1]) {
            cout << "NIE\n";
            return 0;
        }
        int val = query(1, 1, n, k);
        A[i] = val;
        update(1, 1, n, val);
    }

    for (int i = 1; i <= n; i++)
        cout << A[i] << "\n";
}