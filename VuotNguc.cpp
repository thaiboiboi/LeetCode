#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
#define maxN 1001
#define maxM 1001
#define inf 999999999
int td[2]={-1,0};
int tc[2]={0,-1};

typedef pair<int,int> ii;
int n,m;
long long dem=0;

int A[maxN][maxM];
bool check(int i,int j){
    return (i>=1&&i<=n&&j>=1&&j<=m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("VuotNguc.inp","r",stdin);
    freopen("VuotNguc.out","w",stdout);
    cin>>n>>m;
    int d[n+1][m+1]={0};
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            cin>>A[i][j];
            d[i][j]=0;
        }
    d[1][1]=1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        if (A[i][j])
    {
          for(int k=0;k<2;k++){
            int vi=i+td[k];
            int vj=j+tc[k];
            if (check(vi,vj)&&(A[vi][vj]==1))
                d[i][j]+=d[vi][vj]%1000000000;
    }
    }
    cout<<d[n][m]%1000000000;
    return 0;
}






