#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n;
pair<int, int> egg[10];

int mx = 0;
int ans = 0;

void func(int cur)
{
    if (cur == n)
    {
        if (mx < ans)
        {
            mx = ans;
        }
        return;
    }
    if (egg[cur].first <= 0 || ans == n - 1)
    {
        func(cur + 1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (egg[i].first <= 0 || i == cur) continue; //���� �� ������ ������

        egg[cur].first -= egg[i].second;
        egg[i].first -= egg[cur].second;
        if (egg[cur].first <= 0) ans++;
        if (egg[i].first <= 0) ans++;
        
        func(cur + 1);
        
        if (egg[cur].first <= 0) ans--;
        if (egg[i].first <= 0) ans--;
        egg[cur].first += egg[i].second;
        egg[i].first += egg[cur].second;
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //����� �浹��Ű�� ��� ����� ���Ը�ŭ ����� �������� ����
    // ���� ����� �ϳ��� ������ �Ѿ��

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> egg[i].first;   //������
        cin >> egg[i].second;  //����
    }

    func(0);

    cout << mx;
}