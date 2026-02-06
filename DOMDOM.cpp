#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n,h,m;
    freopen("DOMDOM.inp","r",stdin);
    freopen("DOMDOM.out","w",stdout);
    cin>>n1>>h;
    m=n1-round((float)n1/2);
    n=round((float)n1/2);
    int A[n], B[m],t;
    for (int i=1;i<=n1;++i)
        if (i%2==0)
        {
            cin>>B[i/2];
            B[i/2]=h-B[i/2];
        }
        else
        {
            t=round((float)i/2);
            cin>>A[t];
        }
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    int min=n1,sl=1;
    for (int i=1;i<=h;++i)
    {
        int d=0;
        for (int j=1;j<=n;++j)
            if (i<=A[j])
            ++d;
       for (int j=1;j<=m;++j)
            if (h-i+1<=B[j])
            ++d;
        if (d<min)
        {
            min=d;
            sl=1;
        }
        if (d==min)
            ++sl;
    }
    cout <<min<<" "<<sl<< endl;
    return 0;
}
