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
#define mp						make_pair

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

const int inf=INT_MAX-(13*7);
const float PI=acos(-1);
const ll linf=LLONG_MAX-(13ll*7ll);
const int N=105;

int n,topo[N],cnt,deg[N];
vi adj[N];
bool vis[N],d[N],kt;

void toposort(int u){
    if(kt) return;
    d[u]=1;
    FOR(i,0,sz(adj[u]),1){
        int v=adj[u][i];
        if(d[v]&&!vis[v]){
            kt=1;
            return;
        }
        if(!vis[v]) toposort(v);
        if(kt) return;
    }
    topo[++cnt]=u;
    vis[u]=1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("bacsi.inp","r",stdin);
        freopen("bacsi.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FORW(i,1,n,1){
        int k;
        cin>>k;
        FOR(j,0,k,1){
            int u;
            cin>>u;
            adj[u].pb(i);
            ++deg[i];
        }
    }
    FORW(i,1,n,1) sort(adj[i].begin(),adj[i].end(),greater<int>());
    RFOR(i,n,1,1){
        if(deg[i]==0) toposort(i);
    }
    if(kt) {cout<<"0\n"; return 0;}
    cout<<"1\n";
    RFOR(i,n,1,1){
        cout<<topo[i]<<"\n";
    }
}

//Mot nam nua van duoc chu?
//Duoc
