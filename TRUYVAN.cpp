#include <bits/stdc++.h>
using namespace std;
// Typedef
typedef long double                ld;
typedef long long int              int64;
typedef unsigned long long int     uint64;
typedef std::pair<int, int>        PII;
typedef std::pair<int64, int64>    PLL;
typedef std::vector<int>           VI;
typedef std::vector<long long>     VLL;
// Define For-loop
#define FOR(i, j, k, in)           for (int i = (j); i < (k) ; i += (in))
#define FORW(i, j, k, in)          for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)          for (int i = (j); i >= (k); i -= (in))
// Define Data structure func
#define all(cont)                  cont.begin(), cont.end()
#define rall(cont)                 cont.rbegin(), cont.rend()
#define sz(cont)                   int((cont).size())
#define pb                         push_back
#define mp                         make_pair
#define fi                         first
#define se                         second
// Define number
#define IINF                       0x3f3f3f3f
#define LLINF                      1000111000111000111LL
#define PI                         3.1415926535897932384626433832795
// Other
#define lend                       '\n'
#define hardio(name)               freopen(name".inp","r",stdin), freopen(name".out","w",stdout);
void FastIO() { std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); cin.exceptions(cin.failbit); srand(time(NULL)); }

const int MOD = 1e9 + 7, MOD2 = 1e9 + 9;
// ======================================================================

int n, cnt = 0;
int a[100006] = {};

void comp(int pos, int x) {
    if (a[pos] == x) return;
    if (pos - 1 >= 1) {
        if (a[pos - 1] == x) --cnt;
        else if (a[pos] == a[pos - 1]) ++cnt;
    }
    if (pos + 1 <= n) {
        if (a[pos + 1] == x) --cnt;
        else if (a[pos] == a[pos + 1]) ++cnt;
    }
    a[pos] = x;
}

int main(int argc, char* argv[]) { FastIO();
#if defined(_DEBUG)
    hardio("input");
#elif !defined(ONLINE_JUDGE)
    hardio("TRUYVAN");
#endif

    cin >> n;
    FORW(i, 1, n, 1) cin >> a[i];

    cnt = 1;
    FORW(i, 1, n - 1, 1) if (a[i] != a[i + 1]) ++cnt;

    int q; cin >> q;
    while (q--) {
        int i, x; cin >> i >> x;
        comp(i, x);
        cout << cnt << '\n';
    }

    return 0; }
