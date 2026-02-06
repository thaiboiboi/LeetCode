#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct d{
   int a,b,c;
};
d mua[5001];
int main()
{
    freopen("MUAVE.inp","r",stdin);
    freopen("MUAVE.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>mua[i].a>>mua[i].b>>mua[i].c;
    for (int i=n;i>=1;--i)
    {
      int lay=min(mua[i].a,min(mua[i].b,mua[i].c));
      if (i-1>0)
       mua[i-1].a+=lay;
      if (i-2>0)
       mua[i-2].b+=lay;
      if (i-3>0)
       mua[i-3].c+=lay;
    }
    cout<<min(mua[1].a,min(mua[1].b,mua[1].c));
    return 0;
}
