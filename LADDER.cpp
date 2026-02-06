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

int a[1000000],n,m;
vi up,down;

int vt(int l,int r,vi a)
{
    int lo=0,hi=sz(a)-1;
    int tmp=-1;
    while (lo<=hi)
    {
        int mid=(lo+hi+1)/2;
        if (a[mid]>=l && a[mid]<=r-1)
            tmp=a[mid],lo=mid+1;
        else if (a[mid]<l)
            lo=mid+1;
        else if (a[mid]>=r)
            hi=mid-1;
    }
    return tmp;
}

int vt2(int l,int r,vi a)
{
    int lo=0,hi=sz(a)-1;
    int tmp=-1;
    while (lo<=hi)
    {
        int mid=(lo+hi+1)/2;
        if (a[mid]>=l && a[mid]<=r-1)
            tmp=a[mid],hi=mid-1;
        else if (a[mid]>=r)
            hi=mid-1;
        else if (a[mid]<l)
            lo=mid+1;
    }
    return tmp;
}

signed main()
{
    freopen("LADDER.INP","r",stdin);
    freopen("LADDER.OUT","w",stdout);
    cin>>n>>m;
    a[n+1]=INT_MAX;
    a[0]=INT_MAX;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        if (a[i]>a[i-1])    up.pb(i-1);
        if (a[i]>a[i+1])    down.pb(i);
    }
    while (m--)
    {
        int l,r;
        cin>>l>>r;
        int imax=vt(l,r,up);
        if (imax==-1)   imax=INT_MIN;
        int jmin=vt2(l,r,down);
        if (jmin==-1)   jmin=INT_MAX;
        if (imax<jmin)  cout<<1<<endl;
        else cout<<0<<endl;
    }
}
