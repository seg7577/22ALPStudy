#include <bits/stdc++.h>
#define MAX 10000 + 1
using namespace std;

int V, E, result = 0;
int Parent[MAX];
vector<pair<int, pair<int, int>>> vec;

int Find(int n)
{
	if (n == Parent[n]) return n;
	return Parent[n] = Find(Parent[n]);
}

bool SameRoot(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

void Group(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y) Parent[y] = x;
}

int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c, { a, b } });
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i <= V; i++) // �ʱ� �ڽ��� �θ� ���� ����
	{
		Parent[i] = i;
	}

	for (int i = 0; i < E; i++)
	{
		if (SameRoot(vec[i].second.first, vec[i].second.second) == false)
		{
			// ���� ��Ʈ�� �ƴ϶�� �׷�ȭ�Ͽ� �ִ� ��Ʈ ����
			Group(vec[i].second.first, vec[i].second.second);
			result += vec[i].first; // ����ġ �����־� ����� �⿩
		}
	}

	cout << result;

	return 0;
}