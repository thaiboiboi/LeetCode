#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
unordered_set <long long> xet;
long long a[6000];
long long x;
int n=-1;
int main()
{
    fastIO;
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    while (cin>>x)
    {
        n++;
        a[n]=x;
    }
    n++;
    sort(a,a+n);
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if ((a[i]+a[j])%2==0 && binary_search(a,a+n,(a[i]+a[j])/2))
                xet.insert((a[i]+a[j])/2);
        }
    }
    cout<<xet.size();
    return 0;
}
