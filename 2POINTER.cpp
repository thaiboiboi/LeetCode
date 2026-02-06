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

const int NMax = 1e6;
int n;
int64 s;
int64 ans = 0;
int64 a[NMax];

int main(int argc, char* argv[]) {
    FastIO;
#ifndef ONLINE_JUDGE
    hardio("2POINTER");
#endif

    cin >> n >> s;
    FOR(i, 0, n, 1) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    int64 sum = 0;
    while (r < n) {
        sum += a[r];
        while (l <= r && sum > 1e18) sum -= a[l], ++l;
        ans += (r - l + 1);
        ++r;
    }

    l = 0, r = 0;
    sum = 0;
    while (r < n) {
        sum += a[r];
        while (l <= r && sum > (s - 1)) sum -= a[l], ++l;
        ans -= (r - l + 1);
        ++r;
    }

    cout << ans << endl;

    return 0;
}