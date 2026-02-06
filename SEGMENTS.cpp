#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 999999999
#define sz(x) (int)(x).size()
#define int long long
#define double long double
#define log2(x)        log(x)/log(2.0)


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,x,y;

struct node{
    int x,y,k;
    node(int x,int y,int k)
    {
        this->x=x;
        this->y=y;
        this->k=k;
    }
};

bool cmp (const node &a, const node &b)
{
    if (a.x < b.x) return 1;
    if (a.x == b.x) return (a.y>b.y);
    return 0;
}

bool check(node u, node v)
{
    return (v.x>=u.x && v.y<=u.y);
}

vector<node> v;

void solve()
{
    stack<int> s;
    cout<<0<<endl;
    s.push(0);
    for (int i=1;i<n;i++)
    {
        node t=v[i];
        while (!s.empty())
        {
            if(check(v[s.top()],t))
                break;
            else s.pop();
        }
        if (s.empty())
            cout<<0<<endl;
        else cout<<v[s.top()].k+1<<endl;
        s.push(i);
    }
}

signed main()
{
    freopen("SEGMENTS.INP","r",stdin);
    freopen("SEGMENTS.OUT","w",stdout);
    fastIO;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.pb(node(x,y,i));
    }
    sort(v.begin(),v.end(),cmp);
    solve();
}
