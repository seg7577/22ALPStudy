#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N, M, A, B, K;

vector<int> graph[1001];	//int Ÿ���� �ܹ��� �׷���
int indegree[1001];

set<int> mustVisit;		//�ʼ� �湮 ���� ���� (set : �ߺ�X, �ڵ� ����)  *�ݵ�� set�̾���ϴ� �� �ƴ�.

int visit[1001];		//�ش� ���������� �ʼ� �湮 ���� �湮 Ƚ��
int route[1001];		//DP : �� ������ ��� ����

int mustVisit_arr[1001];	//�ʼ� �湮 ���� -1�� ����
/*
�Է� :
1. �������� ���� N ������ ���� M
	(1 �� N �� 1000)
2. M���� �ٿ��� ������ ������ �˷��ִ� �������� ����
3. ������ A ���� B �湮�ؾ��� �߰� ������ ���� K
4. �湮�ؾ��� �߰� ���� C1, C2, ��, Ck
*/
void input() {
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}

	cin >> A >> B >> K;
	for (int i = 0; i < K; i++) {
		cin >> u;
		mustVisit.insert(u);
		mustVisit_arr[u] = -1;
	}
}

/*
�ش� ��忡 �湮�ؾ��ϴ��� Ȯ�� ����
*/
bool isInmustVisit(int node) {
	if (mustVisit.find(node) != mustVisit.end()) return true;
	else return false;
}

void Topology() {
	queue<int> que;
	//ó�� ��� ���� 1 <- 
	route[A] = 1;
	//������ 0 �� ���� ��� �߰� <-
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) que.push(i);
	}

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		// Cn ��� �湮
		if (isInmustVisit(now)) visit[now]++;


		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			//�ش� ���(next)�� �ʼ� 
			// ->	��(������ ���(now)�� ��� ����)
			if (visit[next] == visit[now]) {
				route[next] += route[now];
			}
			//�ش� ��尡 �ʼ� x
			// ->	���� ������ �ʼ� ����� �� �״�� ����
			else if (visit[next] < visit[now]) {	//ó���� visit[next]�� 0�� �״ϱ�...
				visit[next] = visit[now];
				route[next] = route[now];
			}
			if (--indegree[next] == 0) que.push(next);
		}
	}
}
/*
��� :
1. ������ �����ϴ� ����� ���� S (S < 2,000,000,000)
1-1. ��ΰ� �������� ���� ��쿣 0�� ���
*/
int main() {
	fastio
		input();
	Topology();

	if (visit[B] == mustVisit.size()) cout << route[B];
	else cout << 0;

	return 0;
}

/*
���� :
1. 1���� N������ ���ڷ� �ٿ��� N���� ������
2. ��� ������ ���̿��� �ϳ��� ���η� �̷����
-> ���� 1��
3. � �����ο��� ����ؼ� �ٽ� �� �����η� ���ƿ� �� ����
-> ��ȯX
4. �߰� �����ε��� �湮 ������ ��� ����
5. ������ �����ϴ� ����� ���� ���
-> DP ����ؾ߰ڱ���...

�Է� :
1. �������� ���� N ������ ���� M
	(1 �� N �� 1000)
2. M���� �ٿ��� ������ ������ �˷��ִ� �������� ����
3. ������ A ���� B �湮�ؾ��� �߰� ������ ���� K
4. �湮�ؾ��� �߰� ���� C1, C2, ��, Ck

��� :
1. ������ �����ϴ� ����� ���� S (S < 2,000,000,000)
1-1. ��ΰ� �������� ���� ��쿣 0�� ���

Ǯ�� : �������� + DP (��� ����)
*?	*?	*10	*30	*60	*100
*?	 ?	*10	*20	*30	*40
*1	*4	*10	*10	*10	*10
*1	*3	*6	 ?	 ?	*?
*1	*2	*3	 ?	 ?	*?
*1	*1	*1	*?	*?	*?

*/