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
const int N=252;
int a[N][N],d[N],t[N];
int n,m,res;
bool vis[N];
int dij(){
    FORW(i,1,n,1) d[i]=inf, vis[i]=0;
    //priority_queue<pii, vii, greater<vii> >pq;
    //pq.push(mp(0,1));
    d[1]=0;
    d[n+1]=inf;
    while(1){
        int pos=n+1;
        FORW(i,1,n,1){
            if(!vis[i]&&(pos==n+1||d[i]<d[pos])){
                pos=i;
            }
        }
        if(pos==n+1) break;
        vis[pos]=1;
        FORW(i,1,n,1){
            if(a[pos][i]&&d[pos]+a[pos][i]<d[i]){
                d[i]=d[pos]+a[pos][i];
                t[i]=pos;
            }
        }
    }
    return d[n];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("cost.inp","r",stdin);
        freopen("cost.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    FOR(i,0,m,1){
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
    }
    int k=dij();
    vi v;
    for(int i=n;i!=0;i=t[i]){
        v.pb(i);
    }
    FOR(i,0,sz(v)-1,1){
        int x=v[i], y=v[i+1];
        a[x][y]*=2;
        a[y][x]*=2;
        res=max(res,abs(dij()-k));
        a[x][y]/=2;
        a[y][x]/=2;
    }
    cout<<res;
}

//-T nghi la t khong the de mat 1 nguoi ban tot nhu m dau =)))
//
