#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int dp[2][100001];
int result[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) // ���̽� �� T�� 0�� �� ������
	{
		cin >> n; // �� ���̽��� n�� �Է�

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++) // dp[i][j]�� ������ �°� �Է¹���
			{
				cin >> dp[i][j];
			}
		}

		result[0][0] = dp[0][0];
		result[1][0] = dp[1][0]; // result�� dp�� ó�� �� ����

		for (int i = 1; i < n; i++) // i��°���� ���� ��, 2ĭ ���� i +- 1 �� ������� Ȯ���Ͽ� �ִ� Ȯ��
		{
			result[0][i] = max(result[1][i - 1], result[1][i - 2]) + dp[0][i];
			result[1][i] = max(result[0][i - 1], result[0][i - 2]) + dp[1][i];
		}

		cout << max(result[0][n - 1], result[1][n - 1]) << "\n"; // n������ �ִ��� ���
	}

	return 0;
}