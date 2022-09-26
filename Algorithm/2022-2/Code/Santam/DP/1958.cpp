#include <bits/stdc++.h>

using namespace std;

int dp[101][101][101]{ };
string s_1, s_2, s_3;

int LCS(int f, int s, int t) //��ȯ ������ ���ڿ� ���� ��ġ 
{
	if (f < 1 || s < 1 || t < 1) return 1;
	if (dp[f][s][t]) return dp[f][s][t];
	if (s_1[f - 1] == s_2[s - 1] && s_2[s - 1] == s_3[t - 1])
	{
		dp[f][s][t] = LCS(f - 1, s - 1, t - 1) + 1;
		return dp[f][s][t];
	}
	dp[f][s][t] = max(LCS(f - 1, s, t), max(LCS(f, s - 1, t), LCS(f, s, t - 1)));
	return dp[f][s][t];

} // ������ ���ڳ��� ��������� ���ϸ鼭 DP����

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s_1 >> s_2 >> s_3;
	int x = s_1.length(), y = s_2.length(), z = s_3.length();
	cout << LCS(x, y, z) - 1;
	return 0;
}
