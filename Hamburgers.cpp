#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define G vector<vll >
#define gg vector<int>
#define F first
#define S second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar
typedef long long ll;
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
 out<<"[";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<",";out<<*it;}cout<<"]";
return out;}
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}
template<typename T>
void debug(T first) {
    cout << first << "\n";
}
template<typename T, typename... Args>
void debug(T first, Args... args) {
    cout << first << " ";
    debug(args...);
}
ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}
string sw;
ll pb, ps, pcc, nb, ns, nc, money;
ll cb, cs, cc;
bool ok(ll need) {
    ll needb = max(need*cb-nb,0LL), needs = max(0LL,need*cs-ns), needc = max(0LL,need*cc-nc);
    ll total = needb*pb + needs*ps + needc*pcc;
    return total <= money;
}
int main()
{
    freopen("Hamburgers.inp","r",stdin);
    freopen("Hamburgers.out","w",stdout);
    cin>>sw>>nb>>ns>>nc>>pb>>ps>>pcc>>money;

    for(auto c : sw) {
        if(c == 'B') cb++;
        else if(c == 'S') cs++;
        else cc++;
    }

    ll l = 0, r = 1e15;
    while((r-l)>1) {
        ll m = l+(r-l)/2;
        if(ok(m))
            l = m;
        else
            r = m-1;
    }
    if(ok(r))
        cout<<r;
    else
        cout<<l;
    return 0;
}
