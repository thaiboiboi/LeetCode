#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int TimKiem(int m,int x,int A[5])
{
    if (x>=0)
    {if (A[x]!=m)
        return TimKiem(m,x-1,A);
    else
        return x;
    }
    return -1;
}
int main()
{
    int n,m,A[5];
    freopen("TimKiemDQ.inp","r",stdin);
    freopen("TimKiemDQ.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>A[i];
    cout<<TimKiem(m,n-1,A);
    return 0;
}
