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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int BASE=311;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

vi visit,parent;
vector<vi> a;
int n,m,cycle_start,cycle_end;

bool dfs(int u,int par)
{
    visit[u]=true;
    for (int v:a[u])
    {
        if (v==par) continue;
        if (visit[v])
        {
            cycle_end=u;    cycle_start=v;  return true;
        }
        parent[v]=u;
        if (dfs(v,parent[v]))
            return true;
    }
    return false;
}

signed main()
{
    freopen("TANGQUA.INP","r",stdin);
    freopen("TANGQUA.OUT","w",stdout);
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n>>m;
        a.clear();
        a.assign(n+1,vi());
        parent.assign(n+1,-1);
        visit.assign(n+1,false);
        cycle_start=-1;
        for (int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            a[u].pb(v); a[v].pb(u);
        }
        for (int u=1;u<=n;u++)
        {
            if (!visit[u] && dfs(u,parent[u]))
                break;
        }
        if (cycle_start==-1) cout<<"N"<<endl;
        else
        {
            vi cycle;
            cycle.pb(cycle_start);
            for (int v=cycle_end; v!=cycle_start; v=parent[v])
                cycle.pb(v);
            if (sz(cycle)==n) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
}
