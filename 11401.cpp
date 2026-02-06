#include <bits/stdc++.h>

using namespace std;
unsigned long long dp[1000002];
unsigned long long n;
int main()
{
    freopen("11401.inp","r",stdin);
    freopen("11401.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    dp[3]=0, dp[4]=1;
    for(unsigned long long i=5;i<=1000000;i++){
        unsigned long long x=i/2-1;
        if(i&1) dp[i]=dp[i-1]+x*(x+1);
        else dp[i]=dp[i-1]+x*(x+1)-x;
    }
    while(cin>>n && n>=3){
        cout<<dp[n]<<endl;
    }
    return 0;
}
