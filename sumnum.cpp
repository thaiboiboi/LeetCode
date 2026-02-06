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

int64 a[100006];

int main(int argc, char* argv[]) {
    FastIO;
#ifndef ONLINE_JUDGE
    hardio("sumnum");
#endif

    int n, q; cin >> n >> q;

    FOR(i, 0, n, 1) cin >> a[i];
    int len = int(sqrt(n + .0)) + 1;
    vector<int64> b(len);
    FOR(i, 0, n, 1) {
        b[i / len] += a[i];
    }

    while (q--) {
        int l, r; cin >> l >> r; --l, --r;
        int64 sum = 0;
        FORW(i, l, r, 0) {
            if (i % len == 0 && i + len - 1 <= r) {
                sum += b[i / len];
                i += len;
            } else {
                sum += a[i];
                ++i;
            }
        }
        cout << sum << endl;
    }



    return 0;
}
