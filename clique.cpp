#include <bits/stdc++.h>
using namespace std;

typedef long double             ld;
typedef long long int           int64;
typedef unsigned long long int  uint64;
typedef pair<int, int>          PII;
typedef pair<int64, int64>      PLL;
typedef vector<int>             VI;
typedef vector<long long>       VLL;
typedef vector<PII>             VII;

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

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[] = {1, -1, 1, 0, -1, 1, 0, -1};

int a[506][506] = {};
VI g[506];

int ans = 0;

void DFS(int u, int p, VI& cur) {
    cur.pb(u);
    ans = max(ans, sz(cur));

    for(int v : g[u]) {
        if (v == p || a[u][v] == 0 || a[v][u] == 0) continue;

        int cnt = 0;
        FOR(i, 0, sz(cur), 1) cnt += a[v][cur[i]];

        if (cnt == sz(cur)) {
            DFS(v, u, cur);
            //a[u][v] = a[v][u] = 0;
            a[v][cur[0]] = a[cur[0]][v] = 0;
        }
    }

    cur.pop_back();
}

void testmaker() {
    ofstream out("input.inp");
    int n = 50;
    vector<PII> a;

    FORW(i, 1, n, 1) FORW(j, i + 1, n, 1) a.pb({i, j});
    out << n << ' ' << sz(a) << endl;
    FOR(i, 0, sz(a), 1) out << a[i].fi << ' ' << a[i].se << '\n';
    out.close();
}

int main(int argc, char* argv[]) {
    FastIO;
#ifndef ONLINE_JUDGE
    hardio("clique");
#endif

    //testmaker();

    int n, m; cin >> n >> m;
    FOR(i, 0, m, 1) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
        a[u][v] = a[v][u] = 1;
    }


    FORW(i, 1, n, 1) {
        VI cur;
        DFS(i, -1, cur);
    }

    cout << ans << endl;

    return 0;
}
