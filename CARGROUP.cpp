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

int n,P,l;
ld maxtime[1001][1001],f[1001];
ld p[1001],w[1001],v[1001];

int main()
{
    freopen("CARGROUP.INP","r",stdin);
    freopen("CARGROUP.OUT","w",stdout);
    cin>>n>>P>>l;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        p[i]=p[i-1]+w[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)   maxtime[i][j]=l/v[i];
            else if (i<j)   maxtime[i][j]=max(maxtime[i][j-1],l/v[j]);
        }
    }
    f[1]=l/v[1];
    for (int i=2;i<=n;i++)
    {
        f[i]=l/v[i]+f[i-1];
        for (int j=1;j<i;j++)
        {
            if (p[i]-p[j-1]<=P)
                f[i]=min(f[i],f[j-1]+maxtime[j][i]);
        }
    }
    cout<<setprecision(2)<<fixed<<f[n];
}
