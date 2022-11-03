#include <bits/stdc++.h>
#define x first
#define y second
#define tp tuple<int,int,int>

using namespace std;

priority_queue<tp, vector<tp>, greater<tp>> pq; // x: ���, y: u, z: v
char board[51][51]{};
int vis[51][51]{};
int d_x[4]{ 0,0,-1,1 };
int d_y[4]{ -1,1,0,0 };
int n, m, t, u, v;


int MST()
{
	int res = 0, find_k = 0; // ����Ʈ���� Ȯ���� ���� ��
	while (find_k < m&&!pq.empty()) //pq����ִ� ��� ����or�õ� 0 --> bfs���
	{
		int cost, s, e;
		tie(cost, s, e) = pq.top(); pq.pop(); //pq���� ������ ���� ���� ������� ���� �κ�
		if (board[s][e]=='1'||vis[s][e]<cost) continue;
		if (board[s][e] == 'K'&& vis[s][e]>10000 ) find_k++, res += cost-1,cost=1; //k������ ���ο� ����� ���� cost=0 ==> �κ� ��������
		vis[s][e] = cost; // �ش� �������� ���� �ּ��� ���鸸 ���� (pq�� �޸� �ʰ� ����)
		for (int dir = 0; dir < 4; dir++)
		{
			pq.push({ cost + 1,s + d_x[dir],e + d_y[dir] });
		} //pq�� �߰��� nxt�� ���� ������ 4�����̵ȴ�.
	}
	if (find_k == m) return res;
	return -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	memset(vis, 10000, sizeof(int) * 51 * 51);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c; cin >> c;
			board[i + 1][j + 1] = c;
			if (c == 'S') pq.push({ 1,i+1,j+1 }); // vis������ ���� cost=1�� ����
		}
	}
	cout << MST() << "\n";
	return 0;
}