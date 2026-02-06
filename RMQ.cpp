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

int st[4*100001],a[100001];
int n,m;

void build(int id,int l,int r)
{
    if (l==r)
    {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}

void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        return ;
    }
    if (l == r) {
        st[id] = v;
        return ;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);
    st[id] = min(st[id*2], st[id*2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return INT_MAX;
    }
    if (u <= l && r <= v) {
        return st[id];
    }
    int mid = (l + r) / 2;
    return min(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}

signed main()
{
    freopen("RMQ.INP","r",stdin);
    freopen("RMQ.OUT","w",stdout);
    fastIO;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while (m--)
    {
        char l;
        int u,v;
        cin>>l>>u>>v;
        if (l=='U')
            update(1,1,n,u,v);
        if (l=='Q')
            cout<<get(1,1,n,u,v)<<endl;
    }
}
