#include <bits/stdc++.h>
#define maxN 610
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

vector<ii> adj[maxN];
int n,m;
int _t,s,t;
int u,v,w;
int mark[maxN],d[maxN];

void dijkstra(int s)
{
    for (int i=1;i<=n;i++)
    {
        d[i]=inf;
        mark[i]=false;
    }
    d[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(ii(0,s));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        if (mark[u]) continue;
        mark[u]=true;

        for (int i=0;i<(int)adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            if (!mark[v]&&d[v]>max(d[u],w))
            {
                d[v]=(max(d[u],w));
                pq.push(ii(d[v],v));
            }

        }
    }
}

int main()
{
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);

	cin>>n>>m>>_t;

	for (int i=0;i<m;++i)
    {

        cin>>u>>v>>w;
        adj[u].push_back(ii(v,w));
    }

	while(_t--)
    {
        cin>>s>>t;
        dijkstra(s);
        if(d[t]!=inf) cout<<d[t]<<endl;
        else cout<<-1<<endl;
    }

}
