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



int main(int argc, char* argv[]) { FastIO();
#if defined(_DEBUG)
    hardio("input");
#elif !defined(ONLINE_JUDGE)
    hardio("NumPage");
#endif

    int n; cin >> n; n += 3;
    int64 ans = 0, cntdigit = 0;

    while (cntdigit <= n) cntdigit += (log10(++ans) + 1);
    if (cntdigit > n) --ans;

    cout << ans << endl;


    return 0; }
