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

int ans,imax,jmax,n;
int a[50001],dp[5001][5001];

signed main()
{
    freopen("LAP.INP","r",stdin);
    freopen("LAP.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (a[i]==a[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if (ans<dp[i][j])
                {
                    ans=dp[i][j];
                    imax=i;
                    jmax=j;
                }
            }
        }
    }
    cout<<ans<<" "<<imax-ans+1<<" "<<1+jmax-ans;
}
