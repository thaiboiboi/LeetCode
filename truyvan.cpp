#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int n,q,tot=0;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("truyvan.inp","r",stdin);
    freopen("truyvan.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])++tot;
    }
    a[0]=1e9+2,a[n+1]=1e9+2;
    ++tot;
    // cout<<tot<<endl;

    cin>>q;
    while(q--){
        int idx,val; cin>>idx>>val;
        if(val==a[idx]){
            cout<<tot<<'\n';
            continue;
        }

        if(a[idx]==a[idx-1]&&val!=a[idx]&&a[idx-1]==a[idx+1])tot+=2;
        else if(a[idx]==a[idx-1]&&val!=a[idx])++tot;
        else if(a[idx]==a[idx+1]&&val!=a[idx])++tot;
        
        if(a[idx]!=a[idx-1]&&val==a[idx-1]&&a[idx+1]==a[idx-1])tot-=2;
        else if(a[idx]!=a[idx-1]&&val==a[idx-1])--tot;
        else if(a[idx]!=a[idx+1]&&val==a[idx+1])--tot;
        a[idx]=val;
        cout<<tot<<'\n';
    }
}