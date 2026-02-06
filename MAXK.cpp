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

int a[200001],ans[200001];
int n,k;

void solve()
{
    deque<int> dq;
    for (int i=1;i<=n;i++)
    {
        while (!dq.empty() && a[i]>a[dq.back()]) dq.pop_back();
        dq.pb(i);
        if (dq.front() + k <= i)    dq.pop_front();
        if (i>=k) ans[i]= dq.front();
    }
}

signed main()
{
    freopen("MAXK.INP","r",stdin);
    freopen("MAXK.OUT","w",stdout);
    fastIO;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    solve();
    for (int i=k;i<=n;i++)
        cout<<a[ans[i]]<<" ";
}
