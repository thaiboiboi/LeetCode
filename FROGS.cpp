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
const int N = 1e6+2;
int n;
//vi v;
int a[N],id[N],v[N],sl;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("frogs.inp","r",stdin);
        freopen("frogs.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FOR(i,0,n,1){
        cin>>a[i];
        /*if((sz(v)==0)||(a[i]>a[v[sz(v)-1]])){
            v.pb(i);
        }
        id[i]=v[sz(v)-1];*/
        if(sl==0||(a[i]>a[v[sl-1]])){
            v[sl++]=i;
        }
        id[i]=sl-1;
    }
    //v.pb(n);
    v[sl++]=n;
    id[n]=n;
    a[n]=-1;
    FOR(i,0,n,1){
        int x;
        cin>>x;
        //cout<<a[v[(id[i]+x>sz(v)-1?sz(v)-1:id[i]+x)]]<<" ";
        cout<<a[v[(id[i]+x>=sl?(sl-1):id[i]+x)]]<<" ";
    }

