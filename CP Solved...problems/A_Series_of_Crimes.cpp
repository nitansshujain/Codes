#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    char ch[r][c];
    int l = 0, b = 0;
    int d1x = 0, d1y = 0, d2x = 0, d2y = 0, d3x = 0, d3y = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == '*' and cnt == 0)
            {
                d1x = i, d1y = j;
                cnt++;
            }
            else if (ch[i][j] == '*' and cnt == 1)
            {
                d2x = i, d2y = j;
                cnt++;
            }
            else if (ch[i][j] == '*' and cnt == 2)
            {
                d3x = i, d3y = j;
                cnt++;
            }
        }
    }

    if ()

        return 0;
}