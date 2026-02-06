#include <iostream>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;
typedef unsigned long long ll;

ll mx=0,_sieve_size;
bitset<20000001> bs;
vector<ll> primes{2,3,5,7,11,13,17,19};
struct f{
  ll L,R;
};
f A[1001];
int test_count;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    float i=23;
    while (i <= _sieve_size)
    {
        if (bs[(ll)i]&&(ll)i%2!=0&&(ll)i%3!=0&&(ll)i%5!=0&&(ll)i%7!=0&&(ll)i%13!=0&&(ll)i%11!=0&&(ll)i%17!=0&&(ll)i%19!=0)//&&i%primes[1]!=0&&i%primes[2]!=0&&i%primes[3]!=0&&i%primes[4]!=0&&i%primes[5]!=0&&i%primes[6]!=0&&i%primes[7]!=0&&i%primes[8]!=0&&i%primes[9]!=0&&i%primes[10]!=0&&i%primes[11]!=0&&i%primes[12]!=0&&i%primes[13]!=0&&i%primes[14]!=0&&i%primes[15]!=0&&i%primes[16]!=0&&i%primes[17]!=0&&i%primes[18]!=0&&i%primes[19]!=0&&i%primes[20]!=0&&i%primes[21]!=0)
        {
           float j =i*i;
           while (j<=_sieve_size)
           {
            bs[j] = 0;
            j+=i;
           }
      primes.push_back((ll)i);
        }
     i+=2;
     }
}

void nhap()
{
   freopen("PRIMECOUNT.inp","r",stdin);
   freopen("PRIMECOUNT.out","w",stdout);
   cin>>test_count;
   for (int i=1;i<=test_count;++i)
   {
       cin>>A[i].L>>A[i].R;
       mx=max(A[i].R,mx);
   }
   sieve(mx);
}

void xuat()
{
   long long sz=(long long)primes.size();
   for (int i=1;i<=test_count; ++i)
   {
       A[i].R=min(primes[sz-1], A[i].R);
       A[i].L=min(primes[sz-1], A[i].L);
       if (A[i].R<*lower_bound(primes.begin(),primes.end(),A[i].R))
        A[i].R=*(lower_bound(primes.begin(),primes.end(),A[i].R)-1);
       cout<<lower_bound(primes.begin(),primes.end(),A[i].R)-lower_bound(primes.begin(),primes.end(),A[i].L)+1<<endl;
   }
}
int main()
{
 ios::sync_with_stdio(false);
 nhap();
 xuat();
 return 0;
}
