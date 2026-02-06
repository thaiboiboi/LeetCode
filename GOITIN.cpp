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
const int N=505;
int n,m,q;
bool vis[N];
ll k,d[N][N];
vi adj[N];

void bfs(int s){
    d[s][s]=0;
    queue<int> q;
    q.push(s);
    while(sz(q)){
        int u=q.front(); q.pop();
        for(auto v:adj[u]){
            if(d[s][v]>d[s][u]+1){
                d[s][v]=d[s][u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("goitin.inp","r",stdin);
        freopen("goitin.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    FORW(i,1,n,1){
        FORW(j,1,n,1){
            d[i][j]=inf;
        }
    }
    FOR(i,0,m,1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FORW(i,1,n,1){
        bfs(i);
    }
    while(cin>>q>>k&&(q!=0||k!=0)){
        int cnt=0;
        FORW(i,1,n,1){
            if(d[q][i]>k) ++cnt;
        }
        cout<<cnt<<"\n";
    }
}

//-T nghi la t khong the de mat 1 nguoi ban tot nhu m dau =)))

