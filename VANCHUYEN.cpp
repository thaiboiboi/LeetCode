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

int mark[1001],d[1001],par[1001];
int c[1001][1001];
int n,m,s,f;

int getmin(){
    int minD=inf, u=0;
    for(int i=1;i<=n;i++)
        if (!mark[i] && minD>d[i]){
            minD=d[i];
            u=i;
        }
    return u;
}

void dijkstra(int s,int f)
{
    for (int i=1;i<=n;i++)
        d[i]=inf, mark[i]=0;
    d[s]=0;
    while (true)
    {
        int u=getmin();
        if (u==0 || u==f) break;
        mark[u]=1;
        for (int v=1;v<=n;v++)
        {
            if (!mark[v] && d[v]>d[u]+c[u][v])
            {
                d[v]=d[u]+c[u][v];
                par[v]=u;
            }
        }
    }
}

void delete_path(int s,int f)
{
    while (f!=s)
    {
        c[f][par[f]]=c[par[f]][f]=inf;
        f=par[f];
    }
}

signed main()
{
    freopen("VANCHUYEN.INP","r",stdin);
    freopen("VANCHUYEN.OUT","w",stdout);
    fastIO;
    cin>>n>>m>>s>>f;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            if (i==j) c[i][j]=0;
            else c[i][j]=inf;
        }
    for (int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        c[u][v]=c[v][u]=w;
    }

    int ans=0;
    dijkstra(s,f);
    ans+=d[f];
    delete_path(s,f);
    dijkstra(f,s);
    if (d[s]==inf) cout<<"NO"<<endl;
    else {
        ans+=d[s];
        cout<<ans;
    }
}
