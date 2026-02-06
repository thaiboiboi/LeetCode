#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define maxN 1010
#define X first
#define Y second
using namespace std;

typedef pair<int,int> ii;

ii a[maxN];
int n,m,s,t;
int u,v,w;
int trace[maxN],c[maxN][maxN],f[maxN][maxN];
vector<int> adj[maxN];

void _delete(int u,int v)
{
    c[u][v]=0;
}

void _add(int u,int v,int w)
{
    c[u][v]+=w;
    adj[u].push_back(v); adj[v].push_back(u);
}

bool _find()
{
    queue<int> q; q.push(s);
    for (int i=1;i<=t;++i) trace[i]=0;
    trace[s]=inf;

    while (!q.empty())
    {
        u=q.front(); q.pop();
        for (int i=0;i<(int)adj[u].size();++i)
        {
            v=adj[u][i];
            if (!trace[v]&&c[u][v]>f[u][v])
            {
                trace[v]=u;
                if (v==t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

void _inc()
{
    v=t;
    int delta=inf;
    do
    {
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
        v=u;
    } while (v!=s);

    v=t;
    do
    {
        u=trace[v];
        f[u][v]+=delta; f[v][u]-=delta;
        v=u;
    } while (v!=s);
}

void order1()
{
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        _add(u,v,1);
    }

    s=1, t=n;

    while (_find()) _inc();

    int ans=0;
    for (int i=1;i<=n;++i) if (f[i][t]) ans+=f[i][t];

    cout<<ans;
}

void order2()
{
    _add(1,1+n,inf-1);
    _add(n,n*2,inf-1);
    for (int i=1;i<=n;++i)
    {
        _add(i,i+n,1);
    }
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        _add(u+n,v,1);
    }
    int tmp;
    cin>>tmp;
    for (int i=0;i<tmp;++i)
    {
        cin>>u; _delete(u,u+n);
    }

    s=1, t=n*2;

    while (_find()) _inc();

    int ans=0;
    for (int i=1;i<=t;++i) if (f[i][t]) ans+=f[i][t];

    cout<<ans;
}

int main()
{
    freopen("TROCHOI.INP","r",stdin);
    freopen("TROCHOI.OUT","w",stdout);
    int tmp1;
    cin>>n>>m>>tmp1;
    if (tmp1==1) order1();
    else order2();
}
