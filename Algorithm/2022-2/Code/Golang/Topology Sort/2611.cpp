#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

#define endl "\n"
using namespace std;

//index : ����, ù��°int : ����� ����, �ι�°int : ���� ����
vector<pair<int, int>> vec[1011];
int indegree[1011];

vector<int> vec_rev[1011];
int score[1011];

vector<int> route[1011];

void TopoSort(int start) {
	queue<int> q;
	q.push(start);
	route[1].push_back(1);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur].at(i).first;
			//���� ��(�ʱ� 0, ���� next��) vs ���� ��(���� ����� ��)
			//1(0) --(6)--> 5 �� ��, cur=1, next=5 score[next] = score[cur] + vec[cur].at(i).second = 0+6
			//2(1) --(3)--> 5		cur=2 , next=5 score[next] = 6 > score[cur] + vec[cur].at(i).second = 1+3
			if (score[next] < score[cur] + vec[cur].at(i).second) {
				score[next] = score[cur] + vec[cur].at(i).second;
				//�� ���ÿ��� 1������ ���� ������ �� Ŭ ��,
				//1�������� ��θ� ���� ��
				route[next] = route[cur];
				route[next].push_back(next);
			}
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio, cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;
		vec[p].push_back({q, r});
		vec_rev[q].push_back(p);
		indegree[q]++;
	}
	TopoSort(1);
	cout << score[1] << endl;
	for (int i = 0; i < route[1].size(); i++) {
		cout << route[1].at(i) << " ";
	}
}

/*
���� : ���� ����
1�� �������� ���, 1�� �������� ���ƿ��� (�߰����� 1�� ������ �� ��)
�ٸ� ���� ��� - 1�� ������ ����ؾ� ��
�� ���θ��� ���� �ο�
1������ ����Ͽ� ���� ���� ������ ��� 1���� �����ϴ� �� ���

�Է� :
1. ������ ���� N (1 ~ N)	
	(1<= N <=1000)
2. ������ ���� M
3. ���� ����  p q r (p�������� q��������, ������ ������ r)
	(1<= p,q <=N, p != q, 1<= r <=100 �ڿ���)

��� :
1. �ְ� ����
2. �� ���� ��� (1������)
	(1�� �������� �����ϰ� ������ ��)

Ǯ�� :
1 �Է�
1-1 N
1-2 for(1~N) -> vec�� �Է�(�ܹ���)	//0�� ���X
2 ���� ���� (1�� ����)
2-1 DP : �ش� ������ ���� ���� �ְ��� ����(���) ���ϱ�
2-1-1 ���� ���� ���� �� �ִ� -> �ش� ������ ����
2-1-2 ���� ������ �˱� ���� ������ ������ �ݴ�Ǵ� �׷��� ����
2-1-2 ���� ���� ���� �� �ִ��� ������ ������ ���(vector[i])�� �߰�(���? ť?�� �߰�)
3 ���
3-1 �ְ� ���� == ���� ������ ���� �� 1�� ������ ����
3-2 ��� 

���� :
1. ������ ������ ��� ������?
->	index : ����, ù��°int : ����� ����, �ι�°int : ���� ����
	vector<pair<int, int>> vec[1011];
2. ��θ� ��� ����ұ�?
*/