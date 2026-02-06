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

const int inf=1e9+7;
const float PI=acos(-1);
const ll linf=1e18l+7;
const int N=12;
int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
int ar[N][N];
int n,k;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("pascal.inp","r",stdin);
        freopen("pascal.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>k;
    do{
        int t=0;
        FORW(i,1,n,1) ar[1][i]=a[i];
        FORW(i,2,n,1){
            FORW(j,1,n-i+1,1){
                ar[i][j]=ar[i-1][j+1]+ar[i-1][j];
            }
        }
        if(ar[n][1]==k){
            FORW(i,1,n,1) cout<<a[i]<<" ";
            break;
        }
    }while(next_permutation(a+1,a+1+n));
}
