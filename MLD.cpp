#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define maxN 2010

using namespace std;

int n,m,s,t,k;
int u,v,w;
int trace[maxN],c[maxN][maxN],f[maxN][maxN];
vector<int> a[maxN];
vector<pair<int,int>> store;

void _reset()
{
    for (int i=0;i<maxN;++i)
    {
        trace[i]=0; a[i].clear();
        for (int j=0;j<maxN;++j) c[i][j]=f[i][j]=0;
    }
}


void _add(int u,int v,int w)
{
    c[u][v]=w;
    a[u].push_back(v); a[v].push_back(u);
}

bool _find()
{
    queue<int> q; q.push(s);
    for (int i=1;i<=n*2+1;++i) trace[i]=0;
    trace[s]=inf;

    while (!q.empty())
    {
        u=q.front(); q.pop();
        for (int i=0;i<(int)a[u].size();++i)
        {
            v=a[u][i];
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

int main()
{
    freopen("MLD.INP","r",stdin);
    freopen("MLD.OUT","w",stdout);

    cin>>m>>n>>k;

    for (int i=1;i<=n;++i) _add(i,i+n,inf);

    for (int i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        u++;v++;
        _add(u+n,v,w);
        store.push_back({u,v});
    }

    s=1; t=n*2;

    while (_find()) _inc();

    int ans=0;
    for (int i=1;i<=n*2;++i) if (f[i][t]) ans+=f[i][t]; cout<<ans<<endl;

    _reset();

    for (int i=1;i<=n;++i) _add(i,i+n,1);

    for (int i=0;i<m;++i)
    {
        u=store[i].first; v=store[i].second;
        _add(v+n,u,1);
    }

    s=n*2+1;
    t=1;

    while (k--)
    {
        cin>>u; u++;
        _add(s,u,1);
    }

    while (_find()) _inc();

    ans=0;
    for (int i=1;i<=n*2+1;++i) if (f[i][t]) ans+=f[i][t]; cout<<ans;
}
