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

#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define forw(i, l, r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define Pi acos(-1.0l)
#define sz(x) int(x.size())
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

const int N = 127;
const int inf = 0x3f3f3f3f;
int n, l;
int dp[N][N][N];
string st;

void chkmn(int &x, int y) {x = min(x, y);}

int main() {
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("dauxe.inp","r",stdin);
    freopen("dauxe.out","w",stdout);
#endif

    cin >> n >> l >> st;

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    forw(i, 0, sz(st)) forw(j, 0 , n + 1) forw(k, 0, sz(st) + 1) {
        if(dp[i][j][k] == inf) continue;
        if(st[i] == 'X') chkmn(dp[i + 1][j][0], dp[i][j][k]);
        else {
            chkmn(dp[i + 1][j][k + 1], dp[i][j][k] + (k + 1 >= l));
            if(j + 1 <= n) chkmn(dp[i + 1][j + 1][0], dp[i][j][k]);
        }
    }

    pii ans = {-1, -1};
    forw(i, 0, n + 1) forw(j, 0, sz(st) + 1) {
        if(dp[sz(st)][i][j] == inf) continue;
        if(ans.fi == -1 || ans.fi > dp[sz(st)][i][j]) ans = mp(dp[sz(st)][i][j], i);
        else if(ans.fi == dp[sz(st)][i][j]) ans.se = min(ans.se, i);
    }
    cout << ans.fi << '\n' << ans.se;
    return 0;
}
