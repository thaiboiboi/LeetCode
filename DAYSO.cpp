#include<bits/stdc++.h>
#include<ext/numeric>
#define fastIO                  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)		for (int i = (j); i > (k); i -= (in))
#define sz(arr)                 ((int)(arr).size())
#define pb                      push_back
#define fi						first
#define se						second
#define mp						make_pair

using namespace std;
using namespace __gnu_cxx;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

const int inf=INT_MAX-(13*7);
const float PI=acos(-1);
const ll linf=LLONG_MAX-(13ll*7ll);
const int N=1005;
int a[N];
vi v;
int n,cnt;

bool kt(int x){
    for(int i=1;i*i*i<=x;++i){
        if(i*i*i==x) return 1;
    }
    return 0;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("dayso.inp","r",stdin);
        freopen("dayso.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FORW(i,1,n,1){
        int x;
        cin>>x;
        if(kt(x))a[++cnt]=x;
    }
    v.pb(a[1]);
    FORW(i,2,cnt,1){
        auto it=upper_bound(v.begin(),v.end(),a[i]);
        if(it==v.end()) v.pb(a[i]);
        else *it=a[i];
    }
    cout<<sz(v)<<endl;
    //for(auto i:v) cout<<i<<" ";
}

//-T nghi la t khong the de mat 1 nguoi ban tot nhu m dau =)))
//
