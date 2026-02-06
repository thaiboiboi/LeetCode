#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (64 - __builtin_clzll(1ll*(x)) - 1)
#define numBit(x) (__builtin_popcountll(1ll*(x)))
#define getBit(x,i) (x>>i&1)
#define Pi acos(-1.0l)
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << '\n';

const int N = 107;
const int M = 1007;
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
map<string,int> idx={{"UP",0},{"LEFT",1},{"RIGHT",2},{"DOWN",3}};
int n,m,k;
pii st;
string s[M];
char a[N][N];
bool vis[N][N][M];

bool ok(int x, int y) {return (0<=x&&x<n&&0<=y&&y<m);}

void dfs(int x, int y, int pos) {
    vis[x][y][pos]=true;
    if(pos==k) return;
    int dir=idx[s[pos]];
    for(int i=1;;i++) {
        int xx=x+i*dx[dir],yy=y+i*dy[dir];
        if(!ok(xx,yy)||a[xx][yy]=='#') break;
        if(vis[xx][yy][pos+1]) continue;
        dfs(xx,yy,pos+1);
    }
}

int main() {
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("car.inp","r",stdin);
    freopen("car.out","w",stdout);
#endif // ONLINE_JUDGE

    cin >> n >> m;
    forw(i,0,n) forw(j,0,m) {
        cin >> a[i][j];
        if(a[i][j]=='S') st=mp(i,j);
    }
    cin >> k;
    forw(i,0,k) cin >> s[i];
    dfs(st.fi,st.se,0);
    forw(i,0,n) forw(j,0,m) {
        if(vis[i][j][k]) cout << '*';
        else {
            if(st.fi==i&&st.se==j) cout << '.';
            else cout << a[i][j];
        }
        if(j==m-1) cout << '\n';
    }
    return 0;
}
