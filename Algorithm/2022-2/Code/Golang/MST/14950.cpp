#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

int N, M, t; //N=������ ����(���), M=������ ����(����), t=�����Ҷ����� ��� �������
vector<pair<int, pair<int, int>>>edges;	//cost , {����a, ����b}
int parent[10001];

int findParent(int x) {
	if (x == parent[x]) return x;
	else return x = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//�Է�
	cin >> N >> M >> t;
	//Union-Find �⺻ ����
	//�θ� ���̺���, �θ��ڽ��� �ڱ��ڽ����� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {    
		parent[i] = i;
	}
	//���� �Է�
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		//����� �������� �����ϱ� ���� Ʃ���� ù��° ���ҿ� ��� ����    
		edges.push_back({ cost,{a,b} });    
	}
	//����
	sort(edges.begin(), edges.end());

	int ans = 0, cnt = 0;;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			ans += cost + cnt * t;
			cnt++;
		}
	}
	cout << ans;
}
/*
���� : 
1. N���� ����(1������ N��)�� M���� ����
1-1. ��� ���ÿ��� �� ���ø� �����ϴ� ����� ���ΰ� ����
1-2. 1�� ���ÿ��� ����
2. Ư�� ���� B�� �����ϰ� �ʹٸ�, B�� ���η� ����� ���õ� �߿��� ��� �ϳ��� �����ϰ� �־�� �Ѵ�.
3. �� �� ���ð� �����Ǹ�, ��� ���ô� ��踦 �ϰ� �Ǳ� ������ ��� ������ ����� t��ŭ ����

�Է� :
1. ������ ���� N, ������ ���� M, ���� �ø��� �����ϴ� ������ ��� t
	(N<=10000, M<=30000, t<10)
2. M���� �ٵ��� ����A, ����B, ������ ���C
	(A != B, C<= 10000)

��� : 
1. ��� ���ø� �����ϴµ� ���Ǵ� �ּ� ���

Ǯ�� : MST

*/