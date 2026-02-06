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
bool adj[N][N];
int low[N],num[N],ti;
int br,n,m,a;
bool k[N];
void dfs(int u, int pr){
    int c=0;
    num[u]=low[u]=++ti;
    FORW(v,1,n,1){
        if(!adj[u][v]) continue;
        if(v==pr) continue;
        adj[v][u]=0;
        if(!num[v]){
            dfs(v,u);

            if(low[v]==num[v]) adj[v][u]=1;
            low[u]=min(low[v],low[u]);

        }
        else low[u]=min(low[u],num[v]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("street.inp","r",stdin);
        freopen("street.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    int cases=0;
    while(cin>>n>>m&&n!=0&&m!=0){
        ti=0;
        memset(adj,0,sizeof adj);
        memset(num,0,sizeof num);
        memset(low,0,sizeof low);
        FORW(i,1,m,1){
            int u,v;
            cin>>u>>v;
            adj[u][v]=adj[v][u]=1;
        }
        FORW(i,1,n,1){
            if(!num[i]) dfs(i,i);
        }
        cout<<++cases<<"\n\n";
        FORW(i,1,n,1){
            FORW(j,1,n,1){
                if(i!=j&&adj[i][j]) cout<<i<<" "<<j<<"\n";
            }
        }
        cout<<"#\n";
    }
}
