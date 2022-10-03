#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

string word1;
string word2;
string word3;

int dp[101][101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> word1;
	cin >> word2;
	cin >> word3;

	for (int i = 1; i <= word1.size(); i++)
	{
		for (int j = 1; j <= word2.size(); j++)
		{
			for (int k = 1; k <= word3.size(); k++)
			{
				if (word1[i - 1] == word2[j - 1] && word1[i - 1] == word3[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k] , dp[i][j][k - 1] });
				}
			}
		}
	}

	cout << dp[word1.size()][word2.size()][word3.size()];

	// word1�� word2�� LCS1�� ���ϰ� �ش� LCS1�� word3�� LCS2�� ���ϸ� �ȵ�
	// LCS�� 2ȸ �ϴ°Ͱ� 3���� DP�� ������
	// A: dababcf
	//B: ababdef
	//C : df
}
