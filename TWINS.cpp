#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main()
{
 freopen("TWINS.inp","r",stdin);
 freopen("TWINS.out","w",stdout);
 int n,k;
 cin>>n>>k;
 n++;
 int test[n]; int cnt=0;
 vector<int> prime;
 prime.pb(2);
 for(int i=3; i<n; i++){
 test[i]=1;
 }
 for(int i=3; i<n; i+=2){
 if(test[i]==1){
 prime.pb(i);
 for(int j=2; j<=n/i; j++){
 test[i*j]=0;
 }
 }
 }

 for(int i=0; i<static_cast<int>(prime.size())-1; i++){
 if(*lower_bound(prime.begin(),prime.end(),prime[i]+k)==prime[i]+k)cnt++;
 }
 cout<<cnt;
}
