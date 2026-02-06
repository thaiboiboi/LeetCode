#include <iostream>
#include <bits/stdc++.h>

using namespace std;
short A[10001][10001]={0};
int w,h,k,tong=0;

void shoot(int x, int y)
{
    --tong;
    A[x][y]=0;
    if (A[x-1][y])
         shoot(x-1,y);
    if (A[x+1][y])
         shoot(x+1,y);
    if (A[x][y-1])
         shoot(x,y-1);
    if (A[x][y+1])
         shoot(x,y+1);
}

int main()
{
    freopen("BATTLESHIP.inp","r",stdin);
    freopen("BATTLESHIP.out","w",stdout);
    cin>>h>>w>>k;
    for (int i=1;i<=h;++i)
          for (int j=1;j<=w;++j)
    {
        cin>>A[i][j];
        if (A[i][j])
            ++tong;
    }
    int x,y;
    for (int i=1;i<=k;++i)
        {
            cin>>x>>y;
            if (A[x][y])
              shoot(x,y);
            cout<<tong<<endl;
        }
    return 0;
}
