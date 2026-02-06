#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tiii;
typedef vector<ii> vii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for(ull i=(l);i<(r);i++)
#define forb(i,r,l) for(ull i=(r);i>=(l);i--)
#define sqr(x) (x)*(x)
#define log2i(x) 32 - __builtin_clz((x)) - 1
#define log2l(x) 64 - __builtin_clzll((x)) - 1
#define inf 1e9+7
#define Pi acos(-1.0)
#define mu(x,y) trunc(exp(log((x))*(y)))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

ull n,dem;
ld l,w;

bool cmp(pair<ld,ld> x, pair<ld,ld> y) {
    return (x.fi<y.fi);
}

int main() {
    fastIO;
    freopen("tuoicay.inp","r",stdin);
    freopen("tuoicay.out","w",stdout);

    while(cin >> n >> l >> w) {
        vector<pair<ld,ld> > a;
        forw(i,0,n) {
            ld x,y;
            cin >> x >> y;
            ld kc=sqrt(sqr(y)-sqr(w)/4.0);
            if (2.0*y>w) a.pb({x-kc,x+kc});
        }
        sort(all(a),cmp);
        ld moc=0,gh=0;
        dem=0;
        int i=0;
        while(gh<l) {
            ld moc_moi=moc;
            for(;i<a.size();i++) {
                if (a[i].fi>moc) break;
                if (a[i].se>=moc_moi) moc_moi=a[i].se;
            }
            if (moc_moi==moc) break;
            dem++;
            moc=gh=moc_moi;
        }
        if (gh>=l) cout << dem;
        else cout << -1;
        cout << '\n';
    }
    return 0;
}
