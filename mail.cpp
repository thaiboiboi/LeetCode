#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL)
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

const int N = 57;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, num = 0;
pii st;
string s[N];
bool vis[N][N];
int h[N][N];
queue<pii> q;

bool inside(int x, int y) {return (0 <= x && x < n && 0 <= y && y < n);}

bool kt(int lb, int ub) {
	if(lb > h[st.fi][st.se] || h[st.fi][st.se] > ub) return false;
    forw(i, 0, n) forw(j, 0, n) vis[i][j] = false;
    q.push(st); vis[st.fi][st.se] = true;
    int cnt = 0;
    while(sz(q)) {
        pii u = q.front(); q.pop();
        if(s[u.fi][u.se] == 'N') cnt++;
        forw(i, 0, 4) {
            int xx = u.fi + dx[i], yy = u.se + dy[i];
            if(!inside(xx, yy) || vis[xx][yy] || h[xx][yy] > ub || h[xx][yy] < lb) continue;
            vis[xx][yy] = true;
            q.push(mp(xx, yy));
        }
    }
    return (cnt == num);
}

int main() {
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("mail.inp","r",stdin);
    freopen("mail.out","w",stdout);
#endif

    cin >> n;
    forw(i, 0, n) {
        cin >> s[i];
        forw(j, 0, n) {
            if(s[i][j] == 'B') st = mp(i, j);
            if(s[i][j] == 'N') num++;
        }
    }
    forw(i, 0, n) forw(j, 0, n) cin >> h[i][j];

    int ans = 1e9 + 7;
    forw(i, 0, n) forw(j, 0, n) {
        int l = h[i][j], r = 1e6;
        while(l < r) {
            int mid = (l + r) / 2;
            if(kt(h[i][j], mid)) r = mid;
            else l = mid + 1;
        }
        if(kt(h[i][j], l)) ans = min(ans, l - h[i][j]);
    }
    cout << ans;
    return 0;
}
