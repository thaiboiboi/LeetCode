#include <bits/stdc++.h>
#define ll long long
#define maxN 1010
#define inf 99999999

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
vii adj[maxN];
bool mark[maxN];
int d[maxN],parent[maxN];
int n,m,u,v,w,s,x,y,z,yeuCau;
int tap[maxN],socola[maxN],hopBut[maxN];

int checkCost1()
{
    int ia=inf;
    for (int i=1;i<=n;i++)
    {
        if (tap[i]!=inf) ia=min(ia,d[i]+tap[i]);
    }
    return ia;
}

int checkCost2()
{
    int ia=inf;
    for (int i=1;i<=n;i++)
    {
        if (socola[i]!=inf) ia=min(ia,d[i]+socola[i]);
    }
    return ia;
}

int checkCost3()
{
    int ia=inf;
    for (int i=1;i<=n;i++)
    {
        if (hopBut[i]!=inf) ia=min(ia,d[i]+hopBut[i]);
    }
    return ia;
}

int checkCost4()
{
    int ia=inf,ib=inf,iab=inf;
    for (int i=1;i<=n;i++)
    {
        if (tap[i]!=inf) ia=min(ia,d[i]+tap[i]);
        if (socola[i]!=inf) ib=min(ib,d[i]+socola[i]);
        if (tap[i]!=inf&&socola[i]!=inf) iab=min(iab,d[i]+tap[i]+socola[i]);
    }

    return min(ia+ib,iab);
}

int checkCost5()
{
    int ia=inf,ib=inf,iab=inf;
    for (int i=1;i<=n;i++)
    {
        if (tap[i]!=inf) ia=min(ia,d[i]+tap[i]);
        if (hopBut[i]!=inf) ib=min(ib,d[i]+hopBut[i]);
        if (tap[i]!=inf&&hopBut[i]!=inf) iab=min(iab,d[i]+tap[i]+hopBut[i]);
    }

    return min(ia+ib,iab);
}

int checkCost6()
{
    int ia=inf,ib=inf,iab=inf;
    for (int i=1;i<=n;i++)
    {
        if (hopBut[i]!=inf) ia=min(ia,d[i]+hopBut[i]);
        if (socola[i]!=inf) ib=min(ib,d[i]+socola[i]);
        if (hopBut[i]!=inf&&socola[i]!=inf) iab=min(iab,d[i]+hopBut[i]+socola[i]);
    }

    return min(ia+ib,iab);
}

int checkCost7()
{
    int ia=inf,ib=inf,ic=inf,iab=inf,iac=inf,ibc=inf,iabc=inf;
    for (int i=1;i<=n;i++)
    {
        if (tap[i]!=inf) ia=min(ia,d[i]+tap[i]);
        if (socola[i]!=inf) ib=min(ib,d[i]+socola[i]);
        if (hopBut[i]!=inf) ic=min(ic,d[i]+hopBut[i]);
        if (tap[i]!=inf&&socola[i]!=inf) iab=min(iab,d[i]+tap[i]+socola[i]);
        if (tap[i]!=inf&&hopBut[i]!=inf) iac=min(iac,d[i]+tap[i]+hopBut[i]);
        if (socola[i]!=inf&&hopBut[i]!=inf) ibc=min(ibc,d[i]+socola[i]+hopBut[i]);
        if (tap[i]!=inf&&socola[i]!=inf&&hopBut[i]!=inf) iabc=min(iabc,d[i]+tap[i]+socola[i]+hopBut[i]);
    }

    iabc=min(iabc,ia+ib+ic);
    iabc=min(iabc,ia+ibc);
    iabc=min(iabc,ib+iac);
    iabc=min(iabc,ic+iab);

    return iabc;
}

void dijkstra(int s)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=inf; mark[u]=false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[s]=0;
    pq.push(ii(0,s));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(int i=0; i<(int)adj[u].size(); i++)
        {
            int v=adj[u][i].first;
			int w=adj[u][i].second;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                parent[v]=u;
                pq.push(ii(d[v],v));
            }
        }
    }
}
int main()
{
    freopen("SINHNHAT.INP","r",stdin);
    freopen("SINHNHAT.OUT","w",stdout);

    cin>>n>>m>>x>>y>>z>>s>>yeuCau;
    for (int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(ii(v,w));
        adj[v].push_back(ii(u,w));
    }

    int tmp,tmp2;

    for (int i=1;i<=n;i++)
    {
        tap[i]=inf; socola[i]=inf; hopBut[i]=inf;
    }

    for (int i=0;i<x;i++)
    {
        cin>>tmp>>tmp2;
        tap[tmp]=tmp2;
    }

    for (int i=0;i<y;i++)
    {
        cin>>tmp>>tmp2;
        socola[tmp]=tmp2;
    }

    for (int i=0;i<z;i++)
    {
        cin>>tmp>>tmp2;
        hopBut[tmp]=tmp2;
    }

    dijkstra(s);

    if (yeuCau==1) cout<<checkCost1();
    if (yeuCau==2) cout<<checkCost2();
    if (yeuCau==3) cout<<checkCost3();
    if (yeuCau==4) cout<<checkCost4();
    if (yeuCau==5) cout<<checkCost5();
    if (yeuCau==6) cout<<checkCost6();
    if (yeuCau==7) cout<<checkCost7();

    return 0;
}
