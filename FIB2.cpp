#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
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

int a[46],f[46];
int n,k,ans1,ans2;

void init()
{
    a[0]=1,a[1]=0,f[0]=1,f[1]=1;
    for (int i=2;i<=45;i++)
    {
        a[i]=a[i-1]+a[i-2];
        f[i]=f[i-1]+f[i-2];
    }
}

int getans(int n,int k)
{
    if(k == f[n])
        return a[n];
    if(k > f[n - 2])
        return a[n - 2] + getans(n - 1, k - f[n - 2]);
    return getans(n - 2, k);
}

int main()
{
    freopen("FIB2.INP","r",stdin);
    freopen("FIB2.OUT","w",stdout);
    init();
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n>>k;
        cout<<getans(n,k)<<endl;
    }
}
