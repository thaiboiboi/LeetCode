#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Test,s,p,n,sum[1001]={};
int main()
{
    freopen("12455.inp","r",stdin);
    freopen("12455.out","w",stdout);
    cin>>Test;
    while (Test--)
        {
    sum[0]=1;
    cin>>s>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>p;
        for (int j=s-p; j>=0; --j)
           if (sum[j] && !sum[j+p])
                sum[j+p]=1;
    }
     if (sum[s])
            cout<<"YES"<<endl;
    else
           cout<<"NO"<<endl;
        }
    return 0;
}
