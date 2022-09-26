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

int board[2005];
int d[2005][2005];
int N;
int M;
int mid;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	// d[st][en]�� �縰����̷���
	// d[st + 1][en - 1]�� �縰����̾�� ��

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;

		board[i] = num;
		d[i][i] = 1;
		// �ڱ��ڽ� �� n��° �ε������� ~ n��° �ε��������� �縰����̴�.  

		if (i != 1 && board[i - 1] == board[i])
		{
			d[i - 1][i] = 1;
		}

		// �ٷ� �� �ε����� ���� �����ϸ� �縰����̴�. 
	}

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = N; j > i; j--)
		{
			if (board[i] == board[j] && d[i + 1][j - 1] == 1)
			{
				d[i][j] = 1;
			}
		}
	}

	// �ð����⵵ O(N^2) 

	// ���� �ּ��� �����ϰ� �������� �˰����� 
	// ū ������ dp�� ä�����ϹǷ� ��ó�� ������ ������ �ۼ��Ͽ���.
	// ������ ������ ������ ������ dp�� ����� ä������ ����

	//
	/*for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			cout << "d[" << i << "][" << j << "]: " << d[i][j] << '\n';
		}
	}*/

	cin >> M;

	while (M--)
	{
		int st, en;
		cin >> st >> en;
		cout << d[st][en] << '\n';
	}
}
