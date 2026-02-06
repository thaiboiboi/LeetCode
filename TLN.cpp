#include <bits/stdc++.h>

using namespace std;

int n;
int a[6*100000];

int main()
{
    freopen("TLN.inp","r",stdin);
    freopen("TLN.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<max(a[0]*a[1]*a[n-1],a[n-1]*a[n-2]*a[n-3]);
    return 0;
}
