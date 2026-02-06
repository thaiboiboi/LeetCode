/*#include<bits/stdc++.h>
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
const int N=1e4+7;

vi adj[N];
int n,a[N][N],res;
bool vis[N],par[N];

void bfs(int s){
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(sz(q)){
        int x=q.front(); q.pop();
        for(auto i:adj[x]){
            if(!vis[i]&&!par[i]){
                vis[i]=1;
                q.push(i);
                a[s][i]=a[s][x]+1;
                res+=a[s][i];
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("huunghi.inp","r",stdin);
        freopen("huunghi.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FOR(i,0,n-1,1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    FORW(i,1,n,1){
        memset(vis,0,sizeof vis);
        par[i]=1;
        bfs(i);
    }
    cout<<res;
}
*/

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
const int N=1e4+7;

vi adj[N];
int n,a[N],res;
bool vis[N],par[N];

int dfs1(int s){
    vis[s]=1;
    a[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            a[s]+=dfs1(i);
        }
    }
    return a[s];
}

void dfs2(int s,int& res){
    vis[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            res+=a[i]*(n-a[i]);
            dfs2(i,res);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("huunghi.inp","r",stdin);
        freopen("huunghi.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FOR(i,0,n-1,1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1);
    memset(vis,0,sizeof vis);
    dfs2(1,res);
    cout<<res;
}
/*
Mot nam nua van duoc chu?
Duoc
*/
