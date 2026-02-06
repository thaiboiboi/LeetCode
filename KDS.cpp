#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf INT_MAX
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

int n,m1,m2,s,m;
vector<vii> a;
int d[25001];

void dijkstra(int s)
{
    for (int i=1;i<=n;i++)
        d[i]=inf;
    d[s]=0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,s));
    while (!pq.empty())
    {
        int u=pq.top().se;
        pq.pop();
        for (ii i: a[u])
        {
            int v=i.fi;
            int w=i.se;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(ii(d[v],v));
            }
        }
    }
}

signed main()
{
    freopen("KDS.INP","r",stdin);
    freopen("KDS.OUT","w",stdout);
    fastIO;
    cin>>n>>m1>>m2>>s;
    a.assign(n+1,vii());
    for (int i=0;i<m1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].pb(ii(v,w));
        a[v].pb(ii(u,w));
    }
    for (int i=0;i<m2;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].pb(ii(v,w));
    }
    m=m1+m2;
    dijkstra(s);
    for (int i=1;i<=n;i++)
    {
        if (d[i]==inf)
            cout<<"NO PATH"<<endl;
        else cout<<d[i]<<endl;
    }
}
