#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001]{};
string s_1, s_2;


int LCS(int f, int s) 
{
	if (f <1 || s < 1 ) return 1; //�ʱⰪ 1: Ž���� ������ 0�ΰ�� 0: Ž���� ���� ���
	if (dp[f][s]) return dp[f][s]; //dp�� �� �����ҽ� ��ȯ
	if (s_1[f - 1] == s_2[s - 1]) //������ ���ڸ� ���� ���� �� LCS(f-1,s-1)������ ���ڿ����� �ִ밪�� +1�� ���ش�
	{
		dp[f][s]=LCS(f - 1, s - 1) + 1;
		return dp[f][s];
	}
	dp[f][s] = max(LCS(f - 1, s), LCS(f, s - 1)); //������ ���ڰ� �ٸ��ÿ� LCS(f-1,s)�� LCS(f,s-1)�� �ִ밪�߿� ū�� ����
	return dp[f][s];
} // ������ ���ڳ��� ��������� ���ϸ鼭 DP����

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s_1 >> s_2;
	cout << LCS(s_1.length(), s_2.length())-1; // �ʱⰪ ������ ������ 1�� ���־�ߵ�

	return 0;
}