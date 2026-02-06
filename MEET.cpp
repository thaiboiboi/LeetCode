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

vector<vi> a;
int n,m,ans=0;
int t[2000],visit[2000];

int bfs(int s)
{
    int c=1;
    visit[s]=1;
    queue<int> q;
    q.push(s);
    map<int ,int >mp;
    mp.insert({t[s],1});
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int v:a[u])
        {
            if (!visit[v])
            {
                if (mp.find(t[v])==mp.end())
                    mp.insert({t[v],1});
                else mp[t[v]]++;
                visit[v]=1; q.push(v);
                c++;
            }
        }
    }
    int tmp=-1;
    for (auto i=mp.begin();i!=mp.end();i++)
        tmp=max(tmp,i->se);
   return c-tmp;
}

signed main()
{
    freopen("MEET.INP","r",stdin);
    freopen("MEET.OUT","w",stdout);
    cin>>n>>m;
    a.resize(n+1,vi());
    for (int i=1;i<=n;i++)
        cin>>t[i];
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for (int i=1;i<=n;i++)
        if (!visit[i])
            ans+=bfs(i);
    cout<<ans;
}
