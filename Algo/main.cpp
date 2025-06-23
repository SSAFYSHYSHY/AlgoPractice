#include<iostream>
#include<queue>
using namespace std;

int n, k;
queue<int>q;

int main(void)
{
	int i;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		q.push(i);		//	큐에 n까지 삽입
	cout << "<";
	while (q.size() != 0)		//	큐가 빌 때까지 반복
	{
		for (i = 1; i < k; i++)
		{
			q.push(q.front());		//	k-1번째 원소를 맨 뒤에 삽입
			q.pop();			// 	맨 앞에 있던 원소는 삭제
		}
		cout << q.front();		//	k번째 원소가 맨 앞에 오게 됨.
		if (q.size() != 1)
			cout << ", ";
		q.pop();		//	k번째 원소 출력 후 삭제
	}
	cout << ">";
	return 0;
}