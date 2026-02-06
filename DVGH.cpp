#include <bits/stdc++.h>

using namespace std;

#define maxN 1001
#define inf 999999

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> a;
vector<int> d,arr_a,arr_b,arr_c;
vector<bool> mark;
int n,m,customer_point,site_a,site_b,site_c,ans_a=inf,ans_b=inf,ans_c=inf,ans_abc=inf;

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
        for (int i=0;i<(int)a[u].size();i++)
        {
            int v=a[u][i].first;
            int w=a[u][i].second;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(ii(d[v],v));
            }

        }
    }
}


int main()
{
    ifstream ip;
    ofstream op;
    ip.open("DVGH.INP");
    op.open("DVGH.OUT");

    ip>>n>>m>>customer_point>>site_a>>site_b>>site_c;

    a.resize(n+1);
    mark.resize(n+1);
    d.resize(n+1);

    for (int i=1;i<=n;i++) a[i].resize(n+1);

    for (int i=0;i<m;i++)
    {
        int temp1,temp2,val;
        ip>>temp1>>temp2>>val;
        a[temp1].push_back(ii(temp2,val));
        a[temp2].push_back(ii(temp1,val));
    }

    dijkstra(customer_point);



    arr_a.resize(n+1);
    for (int i=0;i<=n;i++) arr_a[i]=inf;
    arr_b.resize(n+1);
    for (int i=0;i<=n;i++) arr_b[i]=inf;
    arr_c.resize(n+1);
    for (int i=0;i<=n;i++) arr_c[i]=inf;

    for (int i=0;i<site_a;i++)
    {
        int temp,val;
        ip>>temp>>val;
        ans_a=min(ans_a,d[temp]+val);
        arr_a[temp]=val;
    }

    op<<ans_a<<endl;

    for (int i=0;i<site_b;i++)
    {

        int temp,val;
        ip>>temp>>val;
        arr_b[temp]=val;

    }
    for (int i=0;i<site_c;i++)
    {

        int temp,val;
        ip>>temp>>val;
        arr_c[temp]=val;
    }
    int ia=inf,ib=inf,ic=inf,iab=inf,iac=inf,ibc=inf,iabc=inf;
    for (int i=1;i<=n;i++)
    {
        if (arr_a[i]!=inf) ia=min(ia,d[i]+arr_a[i]);
        if (arr_b[i]!=inf) ib=min(ib,d[i]+arr_b[i]);
        if (arr_c[i]!=inf) ic=min(ic,d[i]+arr_c[i]);
        if (arr_a[i]!=inf&&arr_b[i]!=inf) iab=min(iab,d[i]+arr_a[i]+arr_b[i]);
        if (arr_a[i]!=inf&&arr_c[i]!=inf) iac=min(iac,d[i]+arr_a[i]+arr_c[i]);
        if (arr_b[i]!=inf&&arr_c[i]!=inf) ibc=min(ibc,d[i]+arr_b[i]+arr_c[i]);
        if (arr_a[i]!=inf&&arr_b[i]!=inf&&arr_c[i]!=inf) iabc=min(iabc,d[i]+arr_a[i]+arr_b[i]+arr_c[i]);
    }
    iabc=min(iabc,ia+ib+ic);
    iabc=min(iabc,ia+ibc);
    iabc=min(iabc,ib+iac);
    iabc=min(iabc,ic+iab);

    op<<iabc;

    ip.close();
    op.close();
    return 0;
}

