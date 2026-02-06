#include<bits/stdc++.h>
#include<ext/numeric>
#define fastIO                  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)		for (int i = (j); i > (k); i -= (in))
#define sz(arr)                 ((int)(arr).size())
#define pb                      push_back
#define fi						first
#define se						second

using namespace std;
using namespace __gnu_cxx;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

const int inf=1e9+7;
const float PI=acos(-1);
const ll linf=1e18l+7;
ll c[70];
ll calc(int n,int k){
    ll s=1;
    FORW(i,1,k,1){
        s*=1ll*(n-i+1);
        s/=1ll*i;
    }
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("bkd.inp","r",stdin);
        freopen("bkd.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    ll m;
    FORW(i,1,60,1) c[i]=calc(i,i/2);
    cin>>m;
    int k;
    FORW(i,1,60,1) if(c[i]>m) {k=i-1; break;}
    cout<<k<<".\n";
}
