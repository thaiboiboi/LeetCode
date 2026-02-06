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
const int N=205;
int a[N][N],n,m,dp[N][N],p,q;
vi win,draw;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("flag.inp","r",stdin);
        freopen("flag.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>m;
    cin>>p>>q;
    FORW(i,1,n,1){
        FORW(j,1,n,1){
            if(i!=j) a[i][j]=1e9+7;
            else a[i][j]=0;
        }
    }
    FOR(k,0,m,1){
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
    }
    FORW(k,1,n,1){
        FORW(i,1,n,1){
            FORW(j,1,n,1){
                if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    FORW(i,1,n,1){
        if(a[p][i]<a[q][i]) win.pb(i);
        else if(a[p][i]==a[q][i]) draw.pb(i);
    }
    sort(win.begin(),win.end());
    sort(draw.begin(),draw.end());
    cout<<sz(win)<<"\n";
    for(auto i:win) cout<<i<<" ";
    if(sz(win))cout<<"\n";
    cout<<sz(draw)<<"\n";
    for(auto i:draw) cout<<i<<" ";
}

//-T nghi la t khong the de mat 1 nguoi ban tot nhu m dau =)))
//
