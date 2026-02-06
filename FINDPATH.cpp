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

int a[501][501],visit[501][501];
int ans,n;

bool check(int i,int j)
{
    return (i>=1 && i<=n && j>=1 && j<=n);
}

void dfs(int x,int i,int j)
{
    visit[i][j]=1;
    for (int k=0;k<4;k++)
    {
        int ui=i+d4i[k];
        int uj=j+d4j[k];
        if (abs(a[i][j]-a[ui][uj])<=x && !visit[ui][uj] && check(ui,uj))
            dfs(x,ui,uj);
    }
}

signed main()
{
    freopen("FINDPATH.INP","r",stdin);
    freopen("FINDPATH.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];

    int l=0,r=1000001;
    while (l<=r)
    {
        int mid=(l+r+1)/2;
        memset(visit,0,sizeof visit);
        dfs(mid,1,1);
        if (visit[n][n])
            r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<ans;
}
