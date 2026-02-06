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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for(int i=(l);i<(r);i++)
#define forb(i,r,l) for(int i=(r);i>(l);i--)
#define sqr(x) (x)*(x)
#define log2(x) 32 - __builtin_clz((x)) - 1
#define inf 1e9+7
#define Pi acos(-1.0)

int n,nt1,nt2,nt3,nt4;
ull m,a[40],b[40],S,ans=0,d[2000000];

int main() {
    fastIO;
    freopen("khuyenmai.inp","r",stdin);
    freopen("khuyenmai.out","w",stdout);

    cin >> n >> m;
    nt1=n/2;
    nt2=n-nt1;
    nt3=1<<nt1;
    nt4=1<<nt2;
    forw(i,0,nt1) cin >> a[i];
    forw(i,nt1,n) cin >> b[i-nt1];
    forw(i,0,nt4) {
        int tmp=i,vt;
        while(tmp) {
            vt=tmp&(-tmp);
            d[i]+=b[log2(vt)];
            tmp^=vt;
        }
    }
    sort(d,d+nt4);
    forw(i,0,nt3) {
        int tmp=i,vt,vt2;
        S=0;
        while(tmp) {
            vt=tmp&(-tmp);
            S+=a[log2(vt)];
            tmp^=vt;
        }
        if (m>=S) {
            vt2=upper_bound(d,d+nt4,m-S)-d;
            ans+=vt2;
        }
    }
    cout << ans;
    return 0;
}
