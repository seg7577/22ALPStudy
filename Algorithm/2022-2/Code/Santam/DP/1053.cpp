#include <bits/stdc++.h>

using namespace std;

int dp[51][51]{},res;
string s,temp_s;

int rec(int f, int s)
{
	if (dp[f][s]!=-1) return dp[f][s];
	if (s - f < 2)
	{
		if (temp_s[f - 1] != temp_s[s - 1]) dp[f][s] = 1; //�ΰ��� �ٸ��� �Ӹ������ �ƴϱ⿡ �߰���,����,��ȯ � ���ε� +1 ���� ����
		else dp[f][s] = 0;
		dp[f][f] = 0;
		dp[s][s] = 0;
		return dp[f][s];
	} //��������
	int op = 0;
	if (temp_s[f - 1] != temp_s[s - 1]) op=1;
	dp[f][s] = min(min(rec(f, s - 1)+1, rec(f + 1, s)+1),rec(f+1,s-1)+op);
	//�糡�� ���� �ٸ� ���� ����,���� ������ ���� �������ٸ� �� �κ��� �Ӹ�����̹Ƿ� ������� �ʿ���� << ������ ��������� ȣ��
	//�糡�� �ٸ��� �����ϳ��� ��ȯ�ϴ� ��쿡�� �糡�� ���̸� �ϳ��� ���� ���뿡�� ����� �ּҰ����� +1 (���ڰ����� +1�� ����)

	return dp[f][s];
}


int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s;
	temp_s = s;
	memset(dp, -1, sizeof(int) * 51 * 51);
	res = rec(1, s.length());
	for (int i = 0; i < s.length()-1; i++)
	{
		for (int j = i+1; j < s.length(); j++)
		{
			memset(dp, -1, sizeof(int) * 51 * 51);
			temp_s = s;
			swap(temp_s[i], temp_s[j]);
			res=min(rec(1, temp_s.length())+1, res); //swap�Ҷ��� ����Ƚ�� +1
		}
	}
	cout << res;
	return 0;
}