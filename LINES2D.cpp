#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int d[1000][3];
int main()
{
 freopen("LINES2D.inp","r",stdin);
 freopen("LINES2D.out","w",stdout);
 int n,dem=0;
 cin>>n;
 for (int i=1; i<=n; i++)
    {
        cin>>d[i][1]>>d[i][2]>>d[i][3];
        if (i>=2)
            for (int j=i-1;j>=1; j--)
               if ( d[i][1]/d[i][2] != d[j][1]/d[j][2])
                 ++dem;
        }
 cout<<dem;
}
