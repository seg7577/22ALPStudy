#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int result = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) // ���� ������ ���� �ʿ��� ���� ����
	{
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2]; // �� �� �� ��� �Է�

		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]); // �� + (�� �� �� ���� ��)
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]); // �� + (�� �� �� ���� ��)
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]); // �� + (�� �� �� ���� ��)
	}

	result = min(min(dp[N][0], dp[N][1]), dp[N][2]); // �� �� �� ��ŸƮ �� � �� �۾�

	cout << result << "\n";

	return 0;
}