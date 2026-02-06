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
const int N=1e6+5;

int n,m;
ll a[N],b[N];
ll fexp(ll x, ll y, ll mod) {
  ll res=0;
  while(y) {
    if(y&1) res=(res+x)%mod;
    x=(x+x)%mod; y>>=1;
  }
  return res%mod;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("missing.inp","r",stdin);
        freopen("missing.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    ll res=0,mod=1;
    FORW(i,1,n,1) cin>>a[i];
    FORW(i,1,n,1) cin>>b[i];
    FORW(i,1,m,1) mod*=10;
    FORW(i,1,n,1){
        res=(res%mod + fexp(a[i],b[i],mod))%mod;
    }
    cout<<res%mod;
}
