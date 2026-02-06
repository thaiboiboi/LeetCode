#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    freopen("timduong.inp","r",stdin);
    freopen("timduong.out","w",stdout);
    while (cin>>n>>m)
    {
        long long A[n+1][m+1],vt[n+1][m+1];
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
             cin>>A[i][j];
        for (int j=2;j<=m;++j)
          for (int i=1;i<=n;++i)
          {
              int mina=A[i][j-1], v=i;
              for (int k=-1;k<=1;++k)
              {
                 int ki=i+k;
                 if (ki==0)
                    ki=n;
                 if (ki==n+1)
                    ki=1;
                 if (A[ki][j-1]<mina)
                 {
                     mina=A[ki][j-1];
                     v=ki;
                 }
                 else
                    if ((A[ki][j-1]==mina)&&(ki<v))
                        v=ki;
              }
              A[i][j]+=mina;
              vt[i][j]=v;
    }
      int  mina=A[1][n],v=1;
      for (int i=2;i<=n;++i)
        if (A[i][m]<mina)
      {
          mina=A[i][m];
          v=i;
      }
      else
        if ((A[i][m]==mina)&&(i<v))
            v=i;
      int d[m];
      d[m]=v;
      for (int j=m-1;j>=1;--j)
        {d[j]=vt[v][j+1];
        v=d[j];}
    for (int i=1;i<=m;++i)
        cout<<d[i]<<" ";
    cout<<endl;
    cout<<mina<<endl;
    }
    return 0;
}
