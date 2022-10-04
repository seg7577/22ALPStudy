#include <bits/stdc++.h>
#include <unordered_map>
#define x first
#define y second
using namespace std;

unordered_map<string, int> m;
string idx_to_s[400001];
vector<int> adj[400001]{};
vector<pair<int, string>> res; //1: �켱������ ���� ���� ����
int n, deg[400001]{};

int BFS()
{
	queue<pair<int, int>> q; // x: �������� �켱����, y:�ش�Ǵ� ������ id��
	for (int i = 1; i <= m.size(); i++)
	{
		if (deg[i] == 0) q.push({ 0,i });
	}
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		res.push_back({ cur.x,idx_to_s[cur.y] }); //���� �湮�� ������ res�� ����
		for (auto cnt : adj[cur.y])
		{
			deg[cnt]--;
			if (deg[cnt] == 0)
			{
				q.push({ cur.x + 1,cnt }); //���� ������ ���� ���������⿡ �켱���� ������ ť�� ����
			}
		}
	}
	for (int i = 1; i <= m.size(); i++)
	{
		if (deg[i]) return -1;
	}
	return 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string u, v;
		cin >> u >> v;
		if (m.find(u) == m.end()) {
			m.insert({ u, m.size() + 1 });
			idx_to_s[m.size()] = u;
		}
		if (m.find(v) == m.end()) {
			m.insert({ v, m.size() + 1 });
			idx_to_s[m.size()] = v;
		}  // map�� �ش� Ű ���翩�� Ȯ�� �� ����
		int u_i = m[u], v_i = m[v]; // �Էµ� string Ű�� �ش��ϴ� �� ã��
		deg[v_i]++;
		adj[u_i].push_back(v_i);
	}
	if (BFS() == -1) cout << -1;
	else
	{
		sort(res.begin(), res.end()); //�̹� ���ͳ��� x:�켱����, y:�����۸����� ����Ǿ� �ֱ⿡ �������ǿ� �°� �����̵ȴ�.
		for (auto a : res) { cout << a.y << "\n"; }
	}
	return 0;
}