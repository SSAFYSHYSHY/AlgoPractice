#include <iostream>
using namespace std;

int N, Q;
bool visited[1100000];

void DFS(int q, int& res) {
    if (visited[q]) {
        res = q;
    }
    if (q == 1) {
        return;
    }
    DFS(q / 2, res);
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        int q; 
        cin >> q;
        
        int res = 0;
        DFS(q, res);
        
        if (res == 0) {
            visited[q] = true;
        }
        cout << res << '\n';
    }

}