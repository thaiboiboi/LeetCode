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
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};

int n;
vector<string> a,b;

bool check()
{
    for (int i=0; i<n; i++)
    {
        if (isdigit(a[i][0]) && isdigit(b[i][0]))
            if (a[i]!=b[i])
                return 0;
    }
    return 1;
}

signed main()
{
    freopen("REPLACE.INP","r",stdin);
    freopen("REPLACE.OUT","w",stdout);
    cin>>n;
    a.resize(n);
    b.resize(n);
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        cin>>b[i];
    if (check())
        cout<<"YES";
    else cout<<"NO";
}
