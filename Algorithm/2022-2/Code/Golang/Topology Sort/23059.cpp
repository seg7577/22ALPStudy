#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 400011
using namespace std;
typedef pair<int, int> pi;

unordered_map<int, string> intToString;
unordered_map<string, int> stringToInt;
vector<int> graph[MAX], ans[MAX];
int indegree[MAX];
int N, j;

bool cmp(int a, int b) {
	return intToString[a] < intToString[b];
}

void print() {
	for (int i = 0; ; i++) {
		if (!ans[i].size()) return;

		sort(ans[i].begin(), ans[i].end(), cmp);
		for (int j = 0; j < ans[i].size(); j++) {
			cout << intToString[ans[i][j]] << '\n';
		}
	}
}

void TopoSort() {
	queue<pi> q;
	for (int i = 0; i < j; i++) {
		if (!indegree[i]) {
			q.push({ i,0 });
			ans[0].push_back(i);
		}
	}

	for (int t = 0; t < j; t++) {
		if (q.empty()) {
			cout << "-1\n";
			return;
		}

		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			indegree[next]--;

			if (!indegree[next]) {
				q.push({ next, cnt + 1 });
				ans[cnt + 1].push_back(next);
			}
		}
	}

	print();
}

int main() {
	ios::sync_with_stdio, cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		//string <-> int
		if (stringToInt.find(s1) == stringToInt.end()) {
			stringToInt.insert({ s1, j });
			intToString.insert({ j++, s1 });
		}
		if (stringToInt.find(s2) == stringToInt.end()) {
			stringToInt.insert({ s2, j });
			intToString.insert({ j++, s2 });
		}
		graph[stringToInt[s1]].push_back(stringToInt[s2]);
		indegree[stringToInt[s2]]++;
	}
	TopoSort();
}
/*
���� :
������ ���̿� �̸� ������ ���� ���� ���� (2�� ���İ���)
1) ���� ������ �� �ִ� ������ �� ���� �������� ���� �������� ��� ã�´�.
2) ã�� �������� ���� ������ ��� �����Ѵ�
���� ������ �ݺ��Ͽ� �������� ������ ��, �������� ��ü ���� ������ �˾Ƴ���.

�Է� :
1. ������ ���� �� N
	(1 �� N �� 200000)
2. �������̸� A(��) B(��)
	(A!=B, 1<=�̸�(string)<=15)

��� :
1. ���� �����ؾ� �ϴ� �����ۺ��� ������� �� �ٿ� ���� ���
1-1. ��� �������� ������ �� ���ٸ� -1 ���

Ǯ�� :
1. string <-> int ��ȯ (��������� ��ȯ�� �����ؾ� ��)
2. �׷��� ����� -> ���� ����
3. ���� �� �Է�

���� :
1. ���� ������� ����Ϸ���?
-> ���Ϳ� �ְ� ���͸� ������
* vector<pair<int, string>> �� �̿��ϸ� ���� ����. ���� �� int -> string ������ �ڵ� ���ĵǱ� ����.

2. �Է� ���� ��� string�� ��, �׷����� ��� �����ؾ� �ϳ�?
->	unordered_map�� �̿�
	unordered_map<int, string> intToString;
	unordered_map<string, int> stringToInt;
	stringToInt.insert({ s1, j });
	intToString.insert({ j++, s1 });

�ð����⵵ :

*/