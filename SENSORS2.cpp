#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1E3+7;

int n,m,q;
long long B[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SENSORS2.inp","r",stdin);
    freopen("SENSORS2.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin>>B[i][j];
            B[i][j] += B[i-1][j] + B[i][j-1] -B[i-1][j-1];
        }
    int x1,x2,y1,y2;
    cin>>q;
    while (q--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<B[x2][y2]-B[x1-1][y2]-B[x2][y1-1]+B[x1-1][y1-1]<<endl;
    }
}