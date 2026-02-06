#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A[10001],n,m,ii,jj;
    freopen("11057.inp","r",stdin);
    freopen("11057.out","w",stdout);
    while (cin>>n)
    {
    for (int i=1;i<=n;++i)
        cin>>A[i];
    cin>>m;
    int min=m;
    sort(A+1,A+1+n);
    for (int i=1;i<=n;++i)
        {
        auto k = lower_bound(A+1,A+n+1,m-A[i] );
        if ((abs(A[i]-*k)<min) && (&A[i]>k))
        {
                ii=*k;
                jj=A[i];
                min=abs(A[i]-*k);
            }
        }
    cout<<"Peter should buy books whose prices are "<<ii<<" and "<<jj<<endl;
    cout<<endl;
    }
    return 0;
}
