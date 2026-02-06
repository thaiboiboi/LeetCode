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
const int N=1e5+2;
int ma[N],fe[N];
int n,res1,res2;
bool km[N],kf[N];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("dance.inp","r",stdin);
        freopen("dance.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n;
    FORW(i,1,n,1){
        cin>>ma[i];
    }
    FORW(i,1,n,1){
        cin>>fe[i];
    }
    sort(ma+1,ma+1+n);
    sort(fe+1,fe+1+n);
    FORW(i,1,n,1){
        int it = lower_bound(fe+1,fe+1+n,abs(ma[i]))-fe;
        if(ma[i]<0&&!kf[it-1]){
            kf[it-1]=1;
            ++res1;
        }else if(it!=n+1&&ma[i]>0&&!kf[it]&&ma[i]<abs(fe[it])){
            kf[it]=1;
            ++res1;
        }else if(it+1!=n+1&&ma[i]>0&&!kf[it+1]&&ma[i]<abs(fe[it+1])){
            kf[it+1]=1;
            ++res1;
        }
    }
    FORW(i,1,n,1){
        int it = lower_bound(ma+1,ma+1+n,abs(fe[i]))-ma;
        if(fe[i]<0&&!km[it-1]){
            km[it-1]=1;
            ++res2;
        }else if(it!=n+1&&fe[i]>0&&!km[it]&&fe[i]<abs(ma[it])){
            km[it]=1;
            ++res2;
        }else if(it+1!=n+1&&fe[i]>0&&!km[it+1]&&fe[i]<abs(ma[it+1])){
            km[it+1]=1;
            ++res2;
        }
    }
    cout<<max(res1,res2);
}
