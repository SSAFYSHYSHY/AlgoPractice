#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

vector<int> v[100002];
bool visited[100002];
//���⼭���� true��� ������� �湮���� �Ȱ��� üũ��.
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

	//üũ�� �Ǿ������� ��ġ�� 1 ����. 
	if (check[1]) {
		match[1] = 1;
	}
	//üũ�� ������ ��ġ 0 ����.
	else {
		match[1] = 0;
	}

	while (!q.empty()) {
		int cx = q.front().x;
		bool cflag = q.front().flag;
		q.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			//�� ���� ��忡 ���ؼ� üũ.
			int nx = v[cx][i];

			//�̸� �湮�� ���̸� üũ.
			if (visited[nx]) continue;	
			//�׷��� ������ 
			else {
				//���� ��Ұ� check true�� �Ǿ� ������.
				//�� ���� ���ʹ� true�� ��ȯ�Ǿ�� ��.
				if (check[nx]) {
					//�̸� ���� match ĭ�� 0���� �湮�Ǿ� ������ 2�� ��ȯ.
					if (match[nx] == 0) {
						match[nx] = 2;
					}
					//-1 �̸� �湮�� ���� �ʾ�����.
					else {
						match[nx] = 1;
					}
					visited[nx] = true;
					q.push({ nx, check[nx] });
				}
				//�׷��� ������ 
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
		//�ƹ� ������ ���� �������� ����.
		if (degree[i] == 0 && (match[i]== 2 || match[i] == 0)) {
			cout << "yes";
			return 0;
		}
	}
	cout << "Yes";
}