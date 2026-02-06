#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m,maxh=0;
vii v;
vector <vi> a,h;
vi par,visit;
int d[10001];

void bfs(int s)
{
    queue<int> q;
    d[s]=0;
    h[0].pb(s);
    q.push(s);
    visit[s]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<sz(a[u]);i++)
        {
            int uu=a[u][i];
            if (!visit[uu])
            {
                visit[uu]=1;
                d[uu]=d[u]+1;
                h[d[uu]].pb(uu);
                q.push(uu);
                maxh=max(maxh,d[uu]);
            }
        }
    }
}

int root(int v)
{
    return par[v]<0 ? v : par[v]=root(par[v]);
}

bool join (int x,int y)
{
    if ((x=root(x))==(y=root(y)))
        return false;
    if (par[y]<par[x])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return true;
}

int main()
{
    freopen("METRO.INP","r",stdin);
    freopen("METRO.OUT","w",stdout);
    cin>>n>>m;
    par.assign(n+1,-1);
    a.resize(n+1);
    h.resize(n);
    visit.assign(n+1,0);
    for (int i=0;i<m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v.pb(ii(t1,t2));
    }
    for (int i=0;i<m;i++)
    {
        if (join(v[i].fi,v[i].se))
            a[v[i].fi].pb(v[i].se),   a[v[i].se].pb(v[i].fi);
    }
    int r;
    for (int i=1;i<=n;i++)
        if (par[i]==-n)
            r=i;
    bfs(r);
    for (int i=maxh;i>=0;i--)
    {
        for (int j=0;j<sz(h[i]);j++)
            cout<<h[i][j]<<endl;
    }
    return 0;
}
