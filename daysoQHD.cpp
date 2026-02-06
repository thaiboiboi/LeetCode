#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,A1=-1001,A2;
    freopen("dayso.inp","r",stdin);
    freopen("dayso.out","w",stdout);
    cin>>n;
    int max=-1001;
    for (int i=1;i<=n;++i)
    {
        cin>>A2;
        if (A2+A1>A2)
            A1+=A2;
        else
            A1=A2;
        if (A1>max)
                max=A1;
    }
    cout<<max;
    return 0;
}
