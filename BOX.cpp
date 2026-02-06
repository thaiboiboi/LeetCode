#include <bits/stdc++.h>
#define maxN 210
#define ll long long
#define inf INT_MAX

using namespace std;

int tmp,a[maxN];
int n,m,s,t;
int u,v,w;
int trace[maxN],c[maxN][maxN],f[maxN][maxN];
vector<int> adj[maxN];
bool isPrime[10010];

void sieve()
{
    for (int i=0;i<10010;++i) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for (int i=2;i*i<=10010;++i)
    {
        if (isPrime[i])
        {
            int j=2;
            while (i*j<=10010)
            {
                isPrime[i*j]=false; j++;
            }
        }
    }
}

void _add(int u,int v,int w)
{
    c[u][v]+=w;
    adj[u].push_back(v); adj[v].push_back(u);
}

bool _find()
{
    queue<int> q; q.push(s);
    for (int i=1;i<=n+2;++i) trace[i]=0;
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
    int odd=0,even=0;
    for (int i=1;i<=n;++i)
        if (a[i]&1) odd++; else even++;
    cout<<min(odd,even);
}

void order2()
{
    sieve();

    vector<pair<int,int>> odd,even;

    for (int i=1;i<=n;++i)
    {
        if (a[i]&1) odd.push_back({a[i],i});
        else even.push_back({a[i],i});
    }

    for (int i=0;i<odd.size();++i)
        for (int j=0;j<even.size();++j)
            if (isPrime[odd[i].first+even[j].first])
                _add(odd[i].second,even[j].second,1);


    s=n+1,t=n+2;
    for (int i=1;i<=n;++i)
    {
        if (a[i]&1) _add(s,i,1);
        else _add(i,t,1);
    }

    while (_find()) _inc();

    int cnt=0;
    for (int i=1;i<=t;++i) if (f[i][t]) cnt+=f[i][t];

    cout<<cnt;
}

int main()
{
    freopen("BOX.INP","r",stdin);
    freopen("BOX.OUT","w",stdout);
    cin>>n>>tmp;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (tmp==1) order1(); else order2();
}
