#include <bits/stdc++.h>
#define inf 1e18
using namespace std;

typedef pair<long long, int> ii;

int n,m,k;
vector<vector<ii> > adj(100000);
long long d[2][100000];

void dijkstra(int s, long long *d) {
    for(int i=1;i<=n;i++) d[i]=inf;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(d[s]=0,s));
    int u,v;
    long long w;
    while(!pq.empty()){
        u=pq.top().second;
        w=pq.top().first;
        pq.pop();
        if (w>d[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            v=adj[u][i].second;
            w=adj[u][i].first;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push(ii(d[v],v));
            }
        }
    }
}

int main()
{
    freopen("duonghoa.inp","r", stdin);
    freopen("duonghoa.out","w", stdout);
    cin>>n>>m;
    adj.clear();
    int u,v;
    long long w,rep=0;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        u++;
        v++;
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
    dijkstra(1,d[0]);
    dijkstra(n,d[1]);
    for(u=1;u<=n;u++){
        for(int i=0;i<adj[u].size();i++){
            v=adj[u][i].second;
            w=adj[u][i].first;
            if (d[0][u]+d[1][v]+w==d[0][n])
                rep+=(w<<1);
        }
    }
    cout<<rep;
    return 0;
}
