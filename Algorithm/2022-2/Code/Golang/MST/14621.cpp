#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>

#define endl "\n"
using namespace std;
tuple<int, int, int> edge[10011];
vector<int> p(1011, -1);
vector<char> University(1011);

bool check_WM(int a, int b) {
	if (University[a] != University[b]) return true;
	return false;
}
//�θ� ��Ʈ ���ϱ�
int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}

//���� ���� �θ�
bool Union(int u, int v) {
	u = find(u);	//u�� ��Ʈ ���
	v = find(v);	//v�� ��Ʈ ���
	if (u == v)return false;	//���� ����
	//�ٸ� ����
	if (u > v) p[v] = u;
	else p[u] = v;
	return true;	//�ٸ� ����
}
int main() {
	ios::sync_with_stdio, cin.tie(0);
	int v, e;	//����, ����
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		char ch;
		cin >> University[i];
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}
	sort(edge, edge + e);
	int count = 0;
	int ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		//W�� M�� �����ϴ� �������� Ȯ�� : true -> Union Find
		if (check_WM(a, b)) {
			if (!Union(a, b)) continue;	//���� �����̸� ���� �߰�x
			ans += cost;	//����ġ ���ϱ�
			count++;
			if (count == v - 1) break;	//MST�� ���� = ���� - 1 �̴�.
		}
	}
	if (count != v - 1) cout << -1 << endl;
	else cout << ans << endl;
}
/*
�޸� �ʰ� :
1. Union()���� u�� v�� ������ ��Ȱ������ �ʰ� P[]�� ����Ͽ����� �޸� �ʰ��� ���Դ�. (���� �����÷ο�)

���� :
1. ��� ��� - ���� ���б��� ���� ���б����� �����ϴ� ���ηθ� �̷����
	-> ���� MST���� ���ʿ� ���ʸ� ������ �� �־�� ��.
2. � ���б������� ��� ���б��� �̵��� ������ ���
3. ����� ���̴� �ִ� �Ÿ�

�Է� :
1. �б��� �� N, ������ ���� M
	(2 �� N �� 1000) (1 �� M �� 10000)
2. �� �б� ���� (���� ���б�M, ���� ���б�W)
3. M���� �ٿ� �б�u �б�v �Ÿ�d
	(1 �� u, v �� N) , (1 �� d �� 1000)

��� :
1. ��� ����
1-1. ��� �б��� �����ϴ� ��ΰ� ���� ��� -1 ���

Ǯ�� :
1. check_WM : W�� M�� �����ϴ� �������� Ȯ�� : true -> Union Find
2. Union, Find : �ٸ� �������� Ȯ�� : true -> ��� ���� ���ϱ�
3. MST �Ϸ� -> ��� ������ ����Ǿ� �ִ��� Ȯ��(Find�� ��Ʈ ��尡 ���� ������ Ȯ��) : true -> ��� ���� ���, false -> -1 ���
*/