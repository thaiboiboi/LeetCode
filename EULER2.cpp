#include <bits/stdc++.h>
#includa <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR2(i, a, b) for (ll i = (a); i <= (b); ++i)
#define mp make_pair
#define pb push_back
#define endl "\n"
#define sp " "

ll n, m, v1, v2, first, x, y, canh;
vll res;
bool noEuler;

int main() {

    freopen("EULER2.INP", "r", stdin);
    freopen("EULER2.OUT", "w", stdout);

    cin >> n >> m;
    canh = m;
    vector <vll> g(n + 5, vll (n + 5));
    vi deg(n + 5);


    FOR(i, 0, m) {
        cin >> x >> y;
        ++g[x - 1][y - 1];
        ++g[y - 1][x - 1];
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            deg[i] += g[i][j];
        }
    }

    first = 0;
    while (!deg[first]) {
        ++first;
    }

    v1 = -1; v2 = -1;
    noEuler = false;
    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                noEuler = true;
        }
    }

    if (v1 != -1) {
        ++g[v1][n];
        ++g[n][v1];
        ++g[n][v2];
        ++g[v2][n];

        first = n;
        ++n;
    }

    stack<int> st;
    st.push(first);

    while(!st.empty()) {
        int v = st.top();
        int k;

        for (k = 0; k < n; ++k) {
            if (g[v][k]) break;
        }

        if (k == n) {
            res.pb(v);
            st.pop();
        } else {
            --g[v][k];
            --g[k][v];
            --canh;
            st.push(k);
        }
    }

    if (canh > 0) noEuler = true;

    if (noEuler) cout << -1 << endl;
    else {
        if (v1 != -1) {
            cout << 1 << endl;
            FOR(i, 1, res.size() - 1) {
                cout << res[i] + 1 << sp;
            }
        } else {
            cout << 2 << endl;
            FOR(i, 0, res.size()) {
                cout << res[i] + 1 << sp;
            }
        }
    }
}
