#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

tuple<int, int, int> edge[200000];
vector<int> p(300, -1);
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

const int MapSize = 55;
bool visit[MapSize][MapSize];
char map[MapSize][MapSize];
int N;
vector<int> x;
vector<int> y;
int BFS(int startX, int startY, int endX, int endY) {
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			visit[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	visit[startX][startY] = true;
	int deep = 0;
	while (!q.empty()) {
		//����(Level) ���ϱ�
		int sz = q.size();
		for (int z = 0; z < sz; z++) {
			pair<int, int> cur = q.front(); q.pop();
			if (cur.first == endX && cur.second == endY) return deep;
			int dx[4] = { 0,-1,0,1 };
			int dy[4] = { 1,0,-1,0 };
			for (int i = 0; i < 4; i++)
			{
				pair<int, int> next = { cur.first + dx[i], cur.second + dy[i] };
				if (next.first < 0 || next.first >= N ||
					next.second < 0 || next.second >= N) continue;
				if (map[next.first][next.second] !='1' && visit[next.first][next.second] == false) {
					q.push({ next.first, next.second });
					visit[next.first][next.second] = true;
				}
			}
		}
		deep++;
	}
	return deep;
}

int main() {
	ios::sync_with_stdio, cin.tie(0);
	int M;
	cin >> N >> M;	//������ ���� : M+1

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S' || map[i][j] == 'K') {
				x.push_back(i);
				y.push_back(j);
			}

		}
	}

	int v = M + 1; //���� ����
	int e = v * (v - 1) / 2;	//��ü ���� ����
	int idx = 0;	//edge
	for (int i = 0; i < x.size()-1; i++)
	{
		for (int j = i+1; j < x.size(); j++)
		{
			//BFS �������� ���� �ֱ�
			//�� �������� ����
			int startX = x.at(i);
			int startY = y.at(i);
			int endX = x.at(j);
			int endY = y.at(j);
			int cost = BFS(startX, startY, endX, endY);
			edge[idx++] = { cost, i, j };
			if (visit[startX][startY] == false || visit[endX][endY] == false) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	sort(edge, edge + e);
	int count = 0;
	int ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if (!Union(a, b)) continue;	//���� �����̸� ���� �߰�x
		ans += cost;	//����ġ ���ϱ�
		count++;
		if (count == v - 1) break;	//MST�� ���� = ���� - 1 �̴�.
	}
	if (count != v - 1) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
/*
������� �� : 
1. ������ ����
1-1. ���� v���� �� ������ ������ v*(v-1)/2 �� ���� Ʋ��.
1-2. �߸� ����Ͽ� edge�� ũ�� ������ OutOfBounds ��Ÿ�� ������ ��.

���� :
1. �κ��� ���� ��ġ�� �̿��ϸ� �ڱ� �ڽ��� �Ȱ��� �κ����� ���ϴ� ������ŭ ������ų �� �ִ�.
1-1. ���谡 �ִ� ����� �κ��� ����ϴ� ��ġ�� �κ��� ������ �� �ִ� ��ġ�� ����
2. �κ��� ���谡 �ִ� ��ġ�� �������� �� ���踦 ã�� ��
3. �ϳ��� ĭ�� ���ÿ� ���� ���� �κ��� ��ġ�� �� ������, �κ��� �� �� ������ �ڸ��� �ٸ� �κ� �Ǵ� �ڱ� �ڽ��� �ٽ� ������ �� �ִ�. 
4. �������� �ð��� ���� ������, �κ��� �����̴� Ƚ���� ���� �п��� �κ� ������ ������ Ƚ���� �� ���� ���Ѵ�. 
5. ������ �κ��� ���踦 ��� ã�� �� ���� ��ġ�� ���� �ʿ�� ����.

�Է� :
1. �̷��� ũ�� N ������ ���� M
	(4 �� N �� 50) (1 �� M �� 250)
2. N° �ٵ��� �̷��� ������ �־���
2-1. 1 : �̷��� ��
2-2. 0 : �����ٴ� �� �ִ� ��
2-3. S : �κ��� ����ϴ� ��ġ (1��)
2-4. K : ������ ��ġ (M��)
2-5. S�� K������ ���� ����

��� :
1. ��� �κ��� ������ Ƚ���� �� ��
1-1. ��� ���踦 ã�� ���� �Ұ����� ��� -1�� ���

Ǯ�� :
1. �������� ����
1-1. �� �̷δ� S�� K�� ������ Ʈ�� ������� �����غ���.
1-2. ��� �κ��� S�� K���� ������ �� ������ ��� �������� ���� K�� ã�� �� �ִ�.
1-3. ���� �� Ʈ���� MST�� ���ϸ� �װ��� �κ��� �̵��� �ּڰ��̴�.
1-4. S������ ������ �����ϴ� MST�� �������� �� S�� �ʿ�� ����.
2. BFS : ����� ���� ���ϱ�
2-1. �Է°� : ����x,y��ǥ, ��x, y��ǥ
2-2. �ݺ� : ������ �� ������ŭ
2-3.��� : ���� == ������ ����ġ 
2-3-1. ��� ���踦 ã�� ���� �Ұ����� ��� -1�� ���
3. MST ����
*/