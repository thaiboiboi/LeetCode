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

int c,l,n,m,tmp,u,v,lo=INT_MAX,hi=-1;
vi par;

struct node{
    int u,v,w,c,l;
    node (int u,int v,int w,int c,int l)
    {
        this->u=u;
        this->v=v;
        this->w=w;
        this->c=c;
        this->l=l;
    }
};

vector<node> edges;

bool cmp(const node &a, const node &b)
{
    return a.w<b.w;
}

int root(int v)
{
    return (par[v]<0) ? v :(par[v]=root(par[v]));
}

bool join(int x,int y)
{
    if ((x=root(x))==(y=root(y)))
        return 0;
    if (par[x]>par[y])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return 1;
}

void init(int k)
{
    for (int i=0;i<m;i++)
        edges[i].w=edges[i].c*1000-edges[i].l*k;
}

void mst()
{
    sort(edges.begin(),edges.end(),cmp);
    for (int i=0;i<m;i++)
    {
        if (join(edges[i].u,edges[i].v))
            tmp+=edges[i].w;
    }
}

signed main()
{
    freopen("NANGCAP.INP","r",stdin);
    freopen("NANGCAP.OUT","w",stdout);
    cin>>n>>m;
    int ans;
    for (int i=0;i<m;i++)
    {
        cin>>u>>v>>c>>l;
        lo=min(lo,1000*c/l);
        hi=max(hi,1000*(c/l+1));
        edges.pb(node(u,v,0,c,l));
    }
    while (lo<=hi)
    {
        int mid=(lo+hi+1)/2;
        par.assign(n+1,-1);
        tmp=0;
        init(mid);
        mst();
        if (tmp<=0)
            ans=mid,hi=mid-1;
        else lo=mid+1;
    }
    cout<<setprecision(3)<<fixed<<(double)ans/1000;
    return 0;
}
