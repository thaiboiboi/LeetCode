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
const int N=10004;
int a[N],s[N],n,res;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("sequence.inp","r",stdin);
        freopen("sequence.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FORW(i,1,n,1){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    FORW(i,1,n,1){
        bool kt=1;
        FORW(j,i,n+i-1,1){
            if(j<=n&&s[j]-s[i-1]<=0){
                kt=0;
                break;
            }else if(j>n&&s[n]-s[i-1]+s[j%n]<=0){
                kt=0;
                break;
            }
        }
        if(kt) ++res;
    }
    cout<<res;
}

//Mot nam nua van duoc chu?
//Duoc
