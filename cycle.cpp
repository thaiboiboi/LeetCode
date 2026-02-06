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
int n,m,d[2504];
struct EDGE{
    int u,v,w;
};
vector<EDGE> adj;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("cycle.inp","r",stdin);
        freopen("cycle.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    FORW(i,1,m,1){
        int x,y,z;
        cin>>x>>y>>z;
        adj.pb({x,y,z});
        //-adj.pb({y,x,z});
    }
    int x;
    FORW(i,1,n,1){
        x=-1;
        for(auto e:adj){
            if(d[e.u] + e.w < d[e.v]){
                d[e.v] = d[e.u] + e.w;
                x=e.v;
            }
        }
    }
    if(x==-1) cout<<"NO"; else cout<<"YES";
}
