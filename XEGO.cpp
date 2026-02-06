#include <iostream>
#include <bits/stdc++.h>
#define MaxTong 5000000000
using namespace std;

int n, l, A[52] = {0};
int DP[52][52] = {};
int main()
{
    freopen("Xego.inp","r",stdin);
    freopen("Xego.out","w",stdout);
    while(scanf("%d", &l) == 1 && l)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        A[++n] = l;
        for(int i = 2; i <= n; i++) {
            for(int khoang= 0, j= i + khoang; j <= n; khoang++, j++)
                {
                int minn = MaxTong, t=0;
                for(int k = khoang+1; k < j; k++)
                {
                    t = DP[khoang][k] + DP[k][j] + A[j] - A[khoang];
                    if(minn > t)
                      minn = t;
                }
                DP[khoang][j] = minn;
            }
        }
        printf("%d\n",DP[0][n]);
    }
    return 0;
}
