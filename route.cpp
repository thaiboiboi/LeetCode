#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("route.inp","r",stdin);
    freopen("route.ans","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    a[n+1]=a[1];

    int i=1,j=2;
    int len=0,ngang=0,xuong=0;
    while(1){
        if(i>=n+1||j>n+1)break;
        if(a[i]<a[j]){
            while(j+1<=n+1&&a[j]<a[j+1])++j;
            ++len;
            i=j;
            ++j;
            continue;
        }
        if(a[i]>a[j]){
            while(j+1<=n+1&&a[j]>a[j+1])++j;
            ++xuong;
            i=j,++j;
            continue;
        }
        if(a[i]==a[j]){
            while(j+1<=n+1&&a[j]==a[j+1])++j;
            ++ngang;
            i=j,++j;
            continue;
        }
    }
    cout<<ngang<<' '<<len<<' '<<xuong;
}