#include <bits/stdc++.h>
#define maxN 1000010
#define log2(x) log(x)/log(2.0)

int a[maxN],mn[maxN][20],mx[maxN][20];
int n,m,c;

using namespace std;

int main()
{
    freopen("THUAM.INP","r",stdin);
    freopen("THUAM.OUT","w",stdout);

    cin>>n>>m>>c;

    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        mn[i][0]=a[i];
        mx[i][0]=a[i];
    }

    for (int j=1;(1<<j)<=n;++j)
    {
        for (int i=1;i+(1<<j)-1<=n;++i)
        {
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        }
    }

    int t=log2(m);
    int ans=0;
    bool mark=false;

    for (int i=1;i+m-1<=n;++i)
    {
        int tmp=min(mn[i][t],mn[i+m-(1<<t)][t]),
            tmp2=max(mx[i][t],mx[i+m-(1<<t)][t]);

        if (tmp2-tmp<=c)
        {
            mark=true;
            cout<<i<<endl;
        }
    }

    if (!mark) cout<<0;
}
