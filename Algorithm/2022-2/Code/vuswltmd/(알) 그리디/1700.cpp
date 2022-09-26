#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n, k;
int sch[101];
int multitap[101] = {0, };

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> sch[i];
    }

    for (int i = 0; i < k; i++)
    {
        bool flag = false;

        // 1. �̹� �����ִٸ�
        for (int j = 0; j < n; j++)
        {
            if (multitap[j] == sch[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }
        
        // 2. ������ �ִٸ�
        for (int j = 0; j < n; j++)
        {
            if (multitap[j] == 0)
            {
                multitap[j] = sch[i];
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }

        int last_need = -1; // ���� ���� �� ���� Ƚ��
        int index = -1;
        // 3. ���� ���� �� �� ������ ã�Ƽ� ���Ƴ���

        for (int j = 0; j < n; j++)
        {
            int count = 0;
            
            for (int b = i + 1; b < k; b++)
            {
                if (sch[b] == multitap[j])
                {
                    break;
                }

                count++;
            }

            if (count > last_need)
            {
                last_need = count;
                index = j;
            }
        }

        multitap[index] = sch[i];
        ans++;
    }

    cout << ans;
}