#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

vector<int> v[100002];
bool visited[100002];
//여기서부터 true라면 다음노드 방문부터 똑같이 체크됨.
bool check[100002];
int degree[100002];
int match[100002];

struct Node {
	int x;
	bool flag;
};

void BFS(int now) {
	queue<Node> q;
	q.push({ 1, check[1] });
	visited[1] = true;

	//체크가 되어있으면 매치에 1 누적. 
	if (check[1]) {
		match[1] = 1;
	}
	//체크가 없으면 매치 0 누적.
	else {
		match[1] = 0;
	}

	while (!q.empty()) {
		int cx = q.front().x;
		bool cflag = q.front().flag;
		q.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			//그 다음 노드에 대해서 체크.
			int nx = v[cx][i];

			//미리 방문된 곳이면 체크.
			if (visited[nx]) continue;	
			//그렇지 않으면 
			else {
				//다음 장소가 check true가 되어 있으면.
				//그 다음 부터는 true로 반환되어야 함.
				if (check[nx]) {
					//미리 다음 match 칸이 0으로 방문되어 있으면 2로 반환.
					if (match[nx] == 0) {
						match[nx] = 2;
					}
					//-1 이면 방문이 되지 않았으니.
					else {
						match[nx] = 1;
					}
					visited[nx] = true;
					q.push({ nx, check[nx] });
				}
				//그렇지 않으면 
				else {
					if (match[nx] == 1) {
						match[nx] = 2;
					}
					else {
						match[nx] = 0;
					}
					visited[nx] = true;
					q.push({ nx, check[nx] });
				}
			}
		}
	}

}

void Input() {
	memset(check, false, sizeof(check));
	memset(visited, false, sizeof(visited));
	memset(match, -1, sizeof(match));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		degree[x]++;
	}

	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;

		check[num] = true;
	}
}

int main() {
	Input();

	BFS(1);

	for (int i = 1; i <= n; i++) {
		//아무 차수가 없는 곳에서의 색출.
		if (degree[i] == 0 && (match[i]== 2 || match[i] == 0)) {
			cout << "yes";
			return 0;
		}
	}
	cout << "Yes";
}