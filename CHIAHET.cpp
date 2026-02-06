#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int A[10001],n,k,c;

int Tinh(int j, int t, int i)
{
    if (i<=n)
    {for (int x=0;x<=1;++x)
        if (j)
         {if (Tinh(x,t+A[i],i+1))
            return 1;}
         else
        {if (Tinh(x,t-A[i],i+1)) return 1;
    }
    else
        if (t%k==0)
        return 1;
void XuLiFile()
{
    int t;
    freopen("CHIAHET.inp","r",stdin);
    freopen("CHIAHET.out","w",stdout);
    cin>>t;
    while (t-->0)
    {
        cin>>n>>k;
        c=0;
        for (int i=1;i<=n;++i)
            cin>>A[i];
        for (int x=0;x<=1;++x)
        if (Tinh(x,A[1],2)==1)
          {cout<<"Yes"<<endl;
          c=1;
          break;}
          if (!c)
        cout<<"No"<<endl;
    }
}
int main()
{
    XuLiFile();
    return 0;
}
