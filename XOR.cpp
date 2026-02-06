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

int st[4*(1<<20+1)],a[1<<20+1];
int n,m,ans;

void build (int id, int l, int r)
{
    if (l==r)
    {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]^st[id*2+1];
}
//
//int getans(int id,int l, int r,int u,int v)
//{
//    if (l>v || r<u)
//        return 0;
//    if (l>=u && r<=v) return st[id];
//    int mid=(l+r)/2;
//    return getans(id*2,l,mid,u,v)^getans(id*2+1,mid+1,r,u,v);
//}

void update(int id,int l,int r,int pos,int val)
{
    if (l>pos || r< pos)
        return;
    if (l==r)
    {
        st[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=st[id*2]^st[id*2+1];
}

signed main()
{
    freopen("XOR.INP","r",stdin);
    freopen("XOR.OUT","w",stdout);
    fastIO;
    cin>>n>>m;
    for (int i=1;i<=(1<<n);i++)
        cin>>a[i];
    ans=a[1];
    for (int i=2;i<=(1<<n);i++)
        ans^=a[i];
    while (m--)
    {
        int l,r;
        cin>>l>>r;
        ans^=a[l];  a[l]=r;
        ans^=a[l];
        cout<<ans<<endl;
    }
//    build(1,1,1<<n);
//    while (m--)
//    {
//        int u,v;
//        cin>>u>>v;
//        update(1,1,1<<n,u,v);
//        cout<<st[1]<<endl;
//    }
}
