#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e12+1, L = 300001;
ll l=N,r,a[L],b[L];
int n;

ll f(ll x) {
    ll t=0;
    for(int i=0;i<=n/2;i++) {
        t+=abs(a[n/2+i]-(x+i))+abs(b[n/2+i]-(x+i));
        if (i) t+=abs(a[n/2-i]-(x+i))+abs(b[n/2-i]-(x+i));
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("xepgach.inp","r",stdin);
    freopen("xepgach.out","w",stdout);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
        l=min(l,b[i]);
        r=max(r,b[i]);
    }
    ll kq;
    while (l<=r) {
        int mid=(l+r)/2;
        if (f(mid)<=f(mid+1)) {
            kq=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << f(kq);
    return 0;
}
