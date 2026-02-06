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
const int N=1e5+7;

vii adj[N];
int n,m,d[2][N];;
int ps,p1,p2;

void dij(int idx,int s){
    d[idx][s]=0;
    priority_queue<pii, vii, greater<pii> > pq;
    pq.push(mp(0,s));
    while(sz(pq)){
        int x=pq.top().se, w=pq.top().fi; pq.pop();
        for(auto i:adj[x]){
            if(d[idx][i.fi]>d[idx][x]+i.se){
                d[idx][i.fi]=d[idx][x]+i.se;
                pq.push(mp(d[idx][i.fi],i.fi));
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("apple.inp","r",stdin);
        freopen("apple.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>m>>n>>ps>>p1>>p2;
    FOR(i,0,2,1){
        FORW(j,1,n,1){
            d[i][j]=inf;
        }
    }
    FOR(i,0,m,1){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    dij(0,p1);
    dij(1,p2);
    cout<<min(d[0][ps]+d[0][p2]+d[0][p1],d[1][ps]+d[1][p1]+d[1][p2]);
}

//-T nghi la t khong the de mat 1 nguoi ban tot nhu m dau =)))
//
