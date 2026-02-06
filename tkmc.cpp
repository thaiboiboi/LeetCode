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
typedef vector<ii> vii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for(int i=(l);i<(r);i++)
#define forb(i,r,l) for(int i=(r);i>(l);i--)
#define sqr(x) (x)*(x)
#define log2i(x) 32 - __builtin_clz((x)) - 1
#define log2l(x) 64 - __builtin_clzll((x)) - 1
#define inf 0x3f3f3f3f
#define Pi acos(-1.0)
#define mu(x,y) trunc(exp(log((x))*(y)))
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N = 301;
int n,m;
int a[N][N];
int d[]={-1,0,0,1}, c[]={0,-1,1,0};
vii b[N];
ii st,des;

bool kt(int x, int y) {
    return (0<=x&&x<n&&0<=y&&y<m);
}

int bfs(int x,int y) {
    vvi visit(N,vi(N,inf));
    queue<ii> q;
    q.push({x,y});
    visit[x][y]=0;
    while(!q.empty()) {
        ii tmp=q.front();
        q.pop();
        forw(i,0,4) {
            int td=tmp.fi+d[i], tc=tmp.se+c[i];
            if (kt(td,tc)&&a[td][tc]!=-3) {
                if (a[td][tc]>0&&b[a[td][tc]].size()>1) {
                    ii vt;
                    if (b[a[td][tc]][0].fi!=td||b[a[td][tc]][0].se!=tc) vt=b[a[td][tc]][0];
                    else vt=b[a[td][tc]][1];
                    if (visit[vt.fi][vt.se]==inf) {
                        visit[vt.fi][vt.se]=visit[tmp.fi][tmp.se]+1;
                        q.push(vt);
                    }
                }
                else if (a[td][tc]==-1&&visit[td][tc]==inf) return (visit[tmp.fi][tmp.se]+1);
                else if (visit[td][tc]==inf) {
                    visit[td][tc]=visit[tmp.fi][tmp.se]+1;
                    q.push({td,tc});
                }
            }
        }
    }
}

int main() {
    fastIO;
    freopen("tkmc.inp","r",stdin);
    freopen("tkmc.out","w",stdout);

    cin >> n >> m;
    forw(i,0,n) {
        forw(j,0,m) {
            char x;
            cin >> x;
            if (x=='#') a[i][j]=-3;
            else if (x=='@') a[i][j]=-2, st.fi=i, st.se=j;
            else if (x=='=') a[i][j]=-1, des.fi=i, des.se=j;
            else if (x=='.') a[i][j]=0;
            else {
                a[i][j]=int(x-'A')+1;
                b[a[i][j]].pb({i,j});
            }
        }
    }
    cout << bfs(st.fi,st.se);
    return 0;
}
