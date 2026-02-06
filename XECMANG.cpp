#include <bits/stdc++.h>
using namespace std;

typedef long double             ld;
typedef long long int           int64;
typedef unsigned long long int  uint64;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<long long>       VLL;
typedef vector<PII>             VII;
typedef vector<VI>              VVI;

#define MEM(a, b)               memset(a, (b), sizeof(a))
#define clr(a)                  fill(a, 0)

#define FOR(i, j, k, in)        for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)       for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)       for (int i = (j); i >= (k); i -= (in))

#define all(cont)               cont.begin(), cont.end()
#define rall(cont)              cont.rbegin(), cont.rend()
#define sz(cont)                int((cont).size())
#define pb                      push_back
#define mp                      make_pair
#define fi                      first
#define se                      second

#define IINF                    0x3f3f3f3f
#define LLINF                   1000111000111000111LL
#define PI                      3.1415926535897932384626433832795

#define FastIO                  ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define hardio(name)            freopen(name".inp","r",stdin), freopen(name".out","w",stdout);
#define endl                    '\n'

int64 a[100006], b[400024] = {};

int64 gcd(int64 a, int64 b) { return (a == 0 ? b : gcd(b % a, a)); }

int64 build(int id, int l, int r) {
    if (l == r) { b[id] = a[l]; return b[id]; }
    int m = (l + r) >> 1;
    b[id] = gcd(build(2 * id, l, m), build(2 * id + 1, m + 1, r));
    return b[id];
}

int64 get(int id, int l, int r, int u, int v) {
    if (l > v || l > r || u > v || u > r) return 0;
    if (u <= l && r <= v) return b[id];
    int m = (l + r) >> 1;
    return gcd(get(2 * id, l, m, u, v), get(2 * id + 1, m + 1, r, u, v));
}

int main(int argc, char* argv[]) {
    FastIO;
#ifndef ONLINE_JUDGE
    hardio("XECMANG");
#endif

    int n; cin >> n;

    FOR(i, 0, n, 1) cin >> a[i];
    build(1, 0, n - 1);

    int l = 0, r = 0;
    int ans = n + 1;

    while (l < n) {
        while (r < n && get(1, 0, n - 1, l, r) != 1) ++r;
        if (r == n) break;
        ans = min(ans, (r - l + 1));
        ++l;
        r = max(r, l);
    }

    cout << (ans == n + 1 ? -1 : ans) << endl;

    return 0;
}