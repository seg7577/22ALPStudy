#include <bits/stdc++.h>

using namespace std;

string dp[1001][1001]{};
string s_1, s_2;


string LCS(int f, int s)
{
	if (f < 1 || s < 1) return "T"; //�ʱⰪ "T": Ž���� ������ 0�ΰ�� NULL: Ž���� ���� ���
	if (!dp[f][s].empty()) return dp[f][s]; //dp�� �� �����ҽ� ��ȯ
	if (s_1[f - 1] == s_2[s - 1]) //������ ���ڸ� ���� ���� �� LCS(f-1,s-1)������ ���ڿ����� �ִ밪�� +1�� ���ش�
	{
		dp[f][s] = LCS(f - 1, s - 1) + s_1[f - 1];
		return dp[f][s];
	}
	string t_1 = LCS(f - 1, s), t_2 = LCS(f, s - 1); //������ ���ڰ� �ٸ��ÿ� LCS(f-1,s)�� LCS(f,s-1)�� �ִ밪�߿� ū�� ����
	t_1.length() > t_2.length() ? dp[f][s] = t_1 : dp[f][s] = t_2;
	return dp[f][s];
} // ������ ���ڳ��� ��������� ���ϸ鼭 DP����

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s_1 >> s_2;
	string s = LCS(s_1.length(), s_2.length());
	cout << s.length() - 1 << "\n"; // �ʱⰪ ������ ������ 1�� ���־�ߵ�
	for (int i = 1; i < s.length(); i++)
	{
		cout << s[i];
	}
	return 0;
}