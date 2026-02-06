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
const int N=1e4+5;
vi adj[N];
int low[N],num[N],ti;
int br,n,m,a;
bool k[N];
void dfs(int u, int pr){
    int c=0;
    num[u]=low[u]=++ti;
    for(auto v:adj[u]){
        if(v==pr) continue;
        if(!num[v]){
            dfs(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]==num[v]) ++br;
            ++c;
            if(u==pr){
                if(c>1) k[u]=1;
            }
            else if(low[v]>=num[u]) k[u]=1;
        }
        else low[u]=min(low[u],num[v]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("graph_.inp","r",stdin);
        freopen("graph_.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    FORW(i,1,m,1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FORW(i,1,n,1){
        if(!num[i]) dfs(i,i);
    }
    cout<<accumulate(k+1,k+1+n,0)<<" "<<br;
}
