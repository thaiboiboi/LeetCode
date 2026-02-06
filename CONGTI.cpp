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

int n,
dp[2*100000+10],visit[2*100000+10];
vector<vector<int> > a;
void dfs(int u)
{
   if (sz(a[u])==0) {dp[u]=0; return ;}
visit[u]=1;
   for (int v: a[u])
         {dfs(v);
   dp[u]+=dp[v]+1;}
}
int main()
{
    freopen("CONGTI.INP","r",stdin);
    freopen("CONGTI.OUT","w",stdout);
     cin>>n;
    a.resize(n+1,vi());
     for (int i=0; i<n-1;i++)
     {
           int u,v;
           cin>>u>>v;
           a[u].pb(v);
     }
     dfs(1);
     for (int i=1;i<=n;i++)
     cout<<dp[i]<<" ";
return 0;
}
