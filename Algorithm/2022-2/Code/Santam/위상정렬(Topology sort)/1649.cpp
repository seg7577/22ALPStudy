#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

vector<int> road[1001];
int vis[1001]{};
int res[1001][2]{}; //0: �ش� ������ ������ ���鼭 ���� �߰����� ����, 1: �ش� ���������� �� ��ΰ���
int deg[1001]{};
int n, m, s, e, k;

int BFS()
{
	queue<pair<int,int>> q; //x:���� ���, y: ������ �߰� ���� ����
	for (int i = 1; i <= n; i++)
	{
		if(deg[i]==0) q.push({i,vis[i]});
	}
	res[s][1] = 1; //�������� ������ �������ߵǴ� �߿�����(�̰��� ��ġ�� ������ ��� ī��Ʈ�� �ȵ�)
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto cnt : road[cur.x])
		{
			deg[cnt]--;
			if (res[cnt][0] == cur.y + vis[cnt]) res[cnt][1] += res[cur.x][1]; //�߿����������� �������� ī��Ʈ
			if (res[cnt][0] < cur.y + vis[cnt])
			{
				res[cnt][0] = cur.y + vis[cnt];
				res[cnt][1] = res[cur.x][1]; //�߿������� ���� ���� ���� ���� ������ ����
			}
			if (cnt == e) continue;
			if (deg[cnt] == 0) q.push({ cnt,res[cnt][0] });
		}
	}
	if (res[e][0] != k) return 0; //�ʼ� ������ �� �� ���������
	return res[e][1]; 
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		deg[v]++;
		road[u].push_back(v);
	}
	cin >> s >> e >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		vis[a] = true;
	}
	cout << BFS();
	return 0;
}