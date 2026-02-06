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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int BASE=311;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,x,y,c;
vi par;

int enemy(int k)
{
    return k+n;
}

int root(int v)
{
    return (par[v]<0) ? v : (par[v]=root(par[v]));
}

void join(int x, int y)
{
    if ((x=root(x))==(y=root(y)))   return;
    if (par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}

signed main()
{
    freopen("10158.INP","r",stdin);
    freopen("10158.OUT","w",stdout);
    cin>>n;
    par.assign(2*n,-1);
    while (cin>>c>>x>>y)
    {
        if (x==0 && y==0 && c==0) break;
        if (c==1)
        {
            if (root(x)==root(enemy(y)) || root(y)==root(enemy(x))) cout<<-1<<endl;
            else join(x,y), join(enemy(x),enemy(y));
        }
        if (c==2)
        {
            if (root(x)==root(y) || root(enemy(x))==root(enemy(y))) cout<<-1<<endl;
            else join(enemy(x),y) , join(x,enemy(y));
        }
        if (c==3)
        {
            if (root(x)==root(y) || root(enemy(x))==root(enemy(y))) cout<<1<<endl;
            else cout<<0<<endl;
        }
        if (c==4)
        {
            if (root(x)==root(enemy(y))|| root(y)==root(enemy(x))) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}
