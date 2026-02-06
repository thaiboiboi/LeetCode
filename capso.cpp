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

const int N = 3e5 + 7;
int n, ma = -1;
int a[N], g[20][N], L[N], R[N];
set<int> pos;

int query(int l, int r) {
    if(l > r) return 0;
    int len = log2i(r - l + 1);
    return __gcd(g[len][l], g[len][r - (1 << len) + 1]);
}

int main() {
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("capso.inp","r",stdin);
    freopen("capso.out","w",stdout);
#endif

    cin >> n;
    forw(i, 0, n) {
        cin >> a[i];
        g[0][i] = a[i];
    }

    forw(i, 1, 20) forw(j, 0, n) {
        if(j + (1 << i) > n) break;
        g[i][j] = __gcd(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
    }

    forw(i, 0, n) {
        for(L[i] = i - 1; L[i] >= 0 && a[L[i]] >= a[i]; L[i] = L[L[i]]);
    }

    forb(i, n - 1, 0) {
        for(R[i] = i + 1; R[i] < n && a[R[i]] >= a[i]; R[i] = R[R[i]]);
    }

    forw(i, 0, n) {
        int lhs = i, rhs = i;
        int l = L[i] + 1, r = i;
        while(l < r) {
            int mid = (l + r) / 2;
            if(query(mid, i) < a[i]) l = mid + 1;
            else r = mid;
        }
        lhs = l;
        l = i, r = R[i] - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(query(i, mid) < a[i]) r = mid - 1;
            else l = mid;
        }
        rhs = r;
        if(ma < rhs - lhs) {
            ma = rhs - lhs;
            pos.clear();
            pos.insert(lhs);
        } else if(ma == rhs - lhs) pos.insert(lhs);
    }
    cout << sz(pos) << ' ' << ma << '\n';
    for(auto x:pos) cout << x + 1 << ' ';
    return 0;
}
