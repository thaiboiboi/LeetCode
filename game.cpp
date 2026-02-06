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
typedef pair<int,pii> piii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

const int inf=0x3f3f3f3f;
const float PI=acos(-1);
const ll linf=1e18l+7;
const int N = 1004;
const int md[8]={-1,-1,-1,0,1,1,1,0};
const int mc[8]={-1,0,1,1,1,0,-1,-1};
int n,m,d[N][N];
char a[N][N];
bool bd(int x,int y){
    return(2<=x&&x<=n-1&&1<=y&&y<=m);
}
void dij(){
    priority_queue<piii, vector<piii>, greater<piii> > pq;
    FORW(i,2,n-1,1){
        d[i][1]=(a[i][1]=='.');
        pq.push(piii(d[i][1],pii(i,1)));
    }
    while(!pq.empty()){
        pii pos=pq.top().se; int w = pq.top().fi; pq.pop();
        if(d[pos.fi][pos.se]<w) continue;
        FOR(k,0,7,1){
            int u=pos.fi + md[k];
            int v=pos.se + mc[k];
            if(bd(u,v)&&d[u][v]>w+(a[u][v]=='.'?1:0)){
                d[u][v]=w+(a[u][v]=='.'?1:0);
                pq.push(piii(d[u][v],pii(u,v)));
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("game.inp","r",stdin);
        freopen("game.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    FORW(i,1,n,1){
        FORW(j,1,m,1){
            cin>>a[i][j];
            d[i][j]=inf;
        }
    }
    dij();
    int res=inf;
    FOR(i,2,n,1){
        res=min(res,d[i][m]);
    }
    cout<<res;
}
