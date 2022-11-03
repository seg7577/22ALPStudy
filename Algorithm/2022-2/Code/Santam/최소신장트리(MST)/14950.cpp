#include <bits/stdc++.h>
#define x first
#define y second
#define tp tuple<int,int,int>

using namespace std;

priority_queue<tp, vector<tp>, greater<tp>> pq; // x: ���, y: u, z: v
vector<pair<int, int>> adj[10001]; // x: ��� , y: v
bool vis[10001]{};
int n, m, t, u, v, d;

void insert_q(int a)
{
	for (auto b : adj[a])
	{
		if (!vis[b.y]) pq.push({ b.x, a, b.y });
	} // ����Ʈ���� ���ο� �����߰��� ���, �ش� ����� next������ ���� push
}


int MST()
{
	vis[1] = 1;
	insert_q(1);
	int res = 0, cnt = 0; // ����Ʈ���� Ȯ���� ���� ��
	while (cnt < n - 1)
	{
		int cost, s, e;
		tie(cost, s, e) = pq.top(); pq.pop();
		if (vis[e]) continue;
		vis[e] = 1;
		cnt++;
		res += cost;
		insert_q(e);
	}
	if (cnt == n - 1) return res;
	return -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m >> t;
	while (m--)
	{
		cin >> u >> v >> d;
		adj[u].push_back({ d,v });
		adj[v].push_back({ d,u });
	}
	cout << MST() + t * (n - 1) * (n - 2) / 2 << "\n";
	return 0;
}