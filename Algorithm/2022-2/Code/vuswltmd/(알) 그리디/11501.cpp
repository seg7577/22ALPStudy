#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// ������ �� �� �ൿ�� ��
// �ֽ��� �Է¼����� �������� ��  �տ� �ͺ��� ���� �ֽ��� ������ ���� �� �Ĵ°� �̵�
// 

int arr[1000001];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }

        int max_val = arr[N - 1];

        long long ans = 0;

        for (int i = N - 2; i >= 0; i--)
        {
            if (arr[i] > max_val) max_val = arr[i];
            ans += max_val - arr[i];
        }

        cout << ans << '\n';
    }
}