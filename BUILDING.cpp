#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 999999999
#define sz(x) (int)(x).size()
#define int long long
#define double long double
#define log2(x)        log(x)/log(2.0)


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m,ans;
int a[501][501],visit[501][501];
vector<pair<int,pair<int,int> > > pr;

bool check(int i,int j)
{
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void dfs(int x,int y)
{
    visit[x][y]=1;
    for (int k=0;k<4;k++)
        if (!visit[x+d4i[k]][y+d4j[k]] && a[x][y]>=a[x+d4i[k]][y+d4j[k]] && check(x+d4i[k],y+d4j[k]))
            dfs(x+d4i[k],y+d4j[k]);
}

signed main()
{
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            pr.pb({a[i][j],{i,j}});
        }
    sort(pr.begin(),pr.end());
    for (int i=sz(pr)-1;i>=0;i--)
    {
        if (!visit[pr[i].se.fi][pr[i].se.se] && pr[i].fi>1)
            dfs(pr[i].se.fi,pr[i].se.se), ans++;
    }
    cout<<ans;
}

