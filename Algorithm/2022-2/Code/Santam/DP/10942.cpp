#include <bits/stdc++.h>

using namespace std;

vector<int> idx;
int dp[2001][2001]{};

void Rec(int s, int e)
{
	if (dp[s][e]>0) return; //dp���� ����� �̹� ������ pass
	if (e - s < 2) {
		 if(idx[s - 1] == idx[e - 1]) dp[s][e] = 2;
		 else dp[s][e] = 1;
		 dp[s][s] = 2;
		 dp[e][e] = 2; //s�� e�� �������� ��� ������ �Ӹ����
		 return;
	} //idx[s]�� idx[e]�� �������� ������ �Ӹ���� (s�� e���̰� 1�����϶�)
	Rec(s + 1, e);
	Rec(s, e - 1); //�� ���� �������� �ϳ��� �ٿ����� dp���� (���⵵ n^2)
	if (dp[s + 1][e - 1]==2 && idx[s - 1] == idx[e - 1]) dp[s][e] = 2; // s,e�� idx�� �����鼭 dp�迭�� s+1,e-1���밡 �Ӹ�����̾�� dp[s][e]�� �Ӹ����
	else dp[s][e] = 1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, q, cnt;
	cin >> n;
	cnt = n;
	while (cnt--)
	{
		int t; cin >> t;
		idx.push_back(t);
	}
	Rec(1, n);
	cin >> q;
	while (q--)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e]-1 << "\n";
	}
}