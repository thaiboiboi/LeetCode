#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long A[10001],q;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SENSORS.inp","r",stdin);
    freopen("SENSORS.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>A[i];
        A[i]+=A[i-1];
    }
    cin>>q;
    int x,y;
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        cout<<A[y]-A[x-1]<<endl;
    }
    return 0;
}
