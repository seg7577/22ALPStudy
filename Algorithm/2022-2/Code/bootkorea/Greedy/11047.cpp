// ������� �˰���
#include <iostream>
#include <algorithm>
#define MAX 1000000 + 1
using namespace std;

int N, idx = 0;
long long K;
int A[MAX];

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = N - 1; i >= 0; i--) // �ڵ����� ū �� ����! ���� ����
	{
		idx += K / A[i];

		K = K % A[i];
	}

	cout << idx;

	return 0;
}