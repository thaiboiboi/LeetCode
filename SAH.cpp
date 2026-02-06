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

int n,k,n1,n2,n3,n4,ans;
int res1[1<<20],res2[1<<20];
ii a[21],b[21];

//bool cmp(const ii &u, const ii & v)
//{
//    return u.se<=v.se;
//}

signed main()
{
    freopen("SAH.INP","r",stdin);
    freopen("SAH.OUT","w",stdout);
    cin>>n>>k;
    n1=n/2;
    n2=n-n1;
    if (n2>n1) swap(n2,n1);
    n3=(1<<n1);
    n4=(1<<n2);
    for (int i=0;i<n1;i++)  cin>>a[i].fi>>a[i].se;
    for (int i=n1;i<n;i++) cin>>b[i-n1].fi>>b[i-n1].se;
    for (int i=0;i<n3;i++)
    {
        int tmp=100000000000,h1=0,s=0;
        bool ok=1;
        for (int j=0;j<n1;j++)
        {
            if (i&(1<<j))
            {
                if (tmp>a[j].fi)
                    tmp=a[j].fi,s+=a[j].se,h1=max(h1,a[j].fi);
                else {ok=false;     break;}
            }
        }
        if (ok) {res1[i]=s;  res2[i]=h1;}
    }
    sort(res1,res1+n3);
    sort(res2,res2+n3);
    for (int i=0;i<n4;i++)
    {
        int tmp=100000000000, h2=100000000000,s=0;
        bool ok=true;
        for (int j=0;j<n2;j++)
        {
            if (i&(1<<j))
            {
                if (tmp>a[j].fi)
                    tmp=a[j].fi, s+=a[j].se, h2=min(h2,a[j].fi);
                else {ok=false; break;}
            }
        }
        if (ok)
        {
            int vt=lower_bound(res2,res2+n3,h2)-res2;
            if (res1[vt]+s>=k)
                ans+=vt;
        }
    }
    cout<<ans;
}
