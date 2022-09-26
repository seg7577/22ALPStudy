#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

int arr[1000000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n; // m:��ī n:���� ��
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	long long st = 0;
	long long en = 1000000000;
	

	while (st < en)
	{
		long long cur = 0;
		long long mid = (st + en + 1) / 2; //

		for (int i = 0; i < n; i++)
		{
			cur += arr[i] / mid;
		}

		if (cur >= m)
		{
			st = mid;
		}
		else
		{
			en = mid - 1;
		}
	}

	cout << st;
	

	//���ڸ� �ɰ��� �ִ� �� �ǰ� 
	// �ٿ��� �ִ� �� �ȵȴ�.
}