#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, p[1005][1005], maxx, sl, temp, k;

int main()
{
    freopen("timhinh2.inp","r",stdin);
    freopen("timhinh2.out","w",stdout);
    fastIO;
    cin >> n;
    for (int i = 0; i <= n; i++) p[i][0] = 0;
    for (int i = 0; i <= n; i++) p[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp; k = 0;
            if (temp == 0) k++;
            if (j < n)
            {
                if (k<=2) p[i][j] = p[i-1][j] + p[i][j-1] - (2*p[i-1][j-1]) + temp;
                    else break;
            }
            else if (j == n)

                if (k<=2) p[i][j] = p[i+1][j] + p[i][j-1] - (2*p[i+1][j-1]) + temp;
                    else break;
            if (maxx < p[i][j])
            {
                maxx = p[i][j];
                sl = 1;
            }
            else if (maxx == p[i][j]) sl++;
        }
     cout << maxx*sl;
}

