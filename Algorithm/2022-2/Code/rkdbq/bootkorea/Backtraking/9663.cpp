#include <iostream>
#include <algorithm>
using namespace std;

int N, result = 0;
bool arr[15][15];

bool Possible(int i, int num)
{
	int x, y;

	for (x = 0; x < num; x++) // �� �� ���� Ž��
	{
		if (arr[i][x] == true) return false;
	}

	for (x = num - 1, y = i - 1; y >= 0; x--, y--) // �»�->���� �밢�� Ž��
	{
		if (arr[y][x] == true) return false;
	}

	for (x = num - 1, y = i + 1; y < N; x--, y++) // ��� -> ���� �밢�� Ž��
	{
		if (arr[y][x] == true) return false;
	}

	return true;
}

void Solve(int num)
{
	if (num == N) // ���� ����!
	{
		result++;
		return;
	}

	for (int i = 0; i < N; i++) // ü���� �迭
	{
		if (!arr[i][num] && Possible(i, num)) // �� �迭�̸� ��ǥ�� ��ϵ��� ���� ���̸�
		{
			arr[i][num] = true; // �迭 ĭ ���������
			Solve(num + 1); // ���� �� Ž���� �������ְ�
			arr[i][num] = false; // ���� ������ ���� �� ������ �ٽ� ���ƿ� �迭 ����
		}
	}
}

int main()
{
	cin >> N;

	Solve(0);

	cout << result;

	return 0;
}