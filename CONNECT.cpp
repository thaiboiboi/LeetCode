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

int n,ans=-1;
vii td;
vi par;

struct node{
    int x,y,w;
    node(int x,int y,int w)
    {
        this->x=x;
        this->y=y;
        this->w=w;
    }
};

int root(int v)
{
    return (par[v]<0) ? v : (par[v]=root(par[v]));
}

bool join(int x,int y)
{
    if ((x=root(x))==(y=root(y)))
        return 0;
    if (par[y]<par[x])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return 1;
}

int kc(ii a,ii b)
{
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

bool cmp(const node &t1, const node &t2)
{
    return t1.w<t2.w;
}

vector<node> edges;

signed main()
{
    freopen("CONNECT.INP","r",stdin);
    freopen("CONNECT.OUT","w",stdout);
    cin>>n;
    par.assign(n+1,-1);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        td.pb(ii(x,y));
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j)
                edges.pb(node(i+1,j+1,kc(td[i],td[j])));
    sort(edges.begin(),edges.end(),cmp);
    for (int i=0;i<sz(edges);i++)
    {
        if(join(edges[i].x,edges[i].y))
            ans=max(ans,edges[i].w);
    }
    cout<<ans;
}
