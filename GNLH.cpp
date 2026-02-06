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

int a[200000],l[200000],r[200000],n;

void solve()
{
    stack<ii> s;
    s.push(ii(0,a[0]));
    l[0]=INT_MIN;
    for (int i=1;i<n;i++)
    {
        while (!s.empty())
        {
            if (s.top().se>a[i])
                break;
            s.pop();
        }
        if (!s.empty())
            l[i]=s.top().fi;
        else l[i]=INT_MIN;
        s.push(ii(i,a[i]));
    }

    while (!s.empty()) s.pop();

    s.push(ii(n-1,a[n-1]));
    r[n-1]=INT_MAX;
    for (int i=n-2;i>=0;i--)
    {
        while (!s.empty())
        {
            if (s.top().se>a[i])
                break;
            s.pop();
        }
        if (!s.empty())
            r[i]=s.top().fi;
        else r[i]=INT_MAX;
        s.push(ii(i,a[i]));
    }

    for (int i=0;i<n;i++)
    {
        if (l[i]==INT_MIN && r[i]==INT_MAX) cout<<9999999<<" ";
        else if (r[i]-i<i-l[i])
            cout<<a[r[i]]<<" ";
        else if (r[i]-i>i-l[i])
            cout<<a[l[i]]<<" ";
        else cout<<max(a[l[i]],a[r[i]])<<" ";
    }
}

signed main()
{
    freopen("GNLH.INP","r",stdin);
    freopen("GNLH.OUT","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    solve();
}
