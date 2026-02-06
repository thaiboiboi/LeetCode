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

int n,m,s1,s2;
int c[300][300];
int p1cur[20*250],p1next[20*250],p2cur[20*250],p2next[20*250];

signed main()
{
    freopen("AGE.INP","r",stdin);
    freopen("AGE.OUT","w",stdout);
    fastIO;
    cin>>n>>m>>s1>>s2;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        c[u][v]=1;
    }
    p1cur[s1]=p2cur[s2]=1;
    bool ok=0;
    int dem=0;
    while (ok==0 && dem<20*n)
    {
        memset(p1next,0,sizeof p1next);
        memset(p2next,0,sizeof p2next);
        dem++;
        for (int i=1;i<=n;i++)
        {
            if (p1cur[i])
            for (int j=1;j<=n;j++)
                if (c[i][j])    p1next[j]=1;
        }

        for (int i=1;i<=n;i++)
        {
            if (p2cur[i])
            for (int j=1;j<=n;j++)
                if (c[i][j])    p2next[j]=1;
        }

        for (int i=1;i<=n;i++)
            if (p1next[i] && p2next[i]) ok=1;
        memset(p1cur,0,sizeof p1cur);
        memset(p2cur,0,sizeof p2cur);
        for (int i=1;i<=n;i++)
        {
            p1cur[i]=p1next[i];
            p2cur[i]=p2next[i];
        }
    }
    if (ok) cout<<dem;
    else cout<<-1;
}
