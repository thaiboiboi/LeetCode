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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m;
vi par;

ll root(ll v)
{
    return par[v]<0 ? v :(par[v]=root(par[v]));
}

bool dsu(ll x, ll y)
{
    if ((x=root(x))==(y=root(y)))   return 0;
    if (par[y]<par[x])  swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return 1;
}

int main()
{
    freopen("Legal1.inp","r",stdin);
    freopen("Legal1.out","w",stdout);
    fastIO;
    int tests;
    cin>>tests;
    while (cin>>n>>m)
    {

        bool ok=false;

        ll ans=1e18+10;
        par.assign(n+1,-1);
        vector< pair<ll,pair<ll,ll> > > ed(m);
        for (int i=0;i<m;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            ed[i].fi=w, ed[i].se.fi=u, ed[i].se.se=v;
        }
        sort(ed.begin(),ed.end());
        for (int i=m-1;i>=0;i--)
        {
            if (dsu(ed[i].se.fi,ed[i].se.se)) ans=ed[i].fi;
            if (root(1)==root(n))   {ok=true; break;}

        }
        cout<<ans<<endl;

    }
}
