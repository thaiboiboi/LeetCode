#include <bits/stdc++.h>

using namespace std;

long long A,B,t=0;

long long check_sum(int n)
{
    check_sum=n;
    for(int i=2;i<=n;i++)
        while (n%i == 0  ) {
            checksum-=i;
            n /= i;
        }
    return abs(check_sum)
}
int main()
{
 freopen("HHH.inp","r",stdin);
 freopen("HHH.out","w",stdout);
 cin>>A>>B;
 for (int i=A; i<=B; i++)
    {
        t+=check_sum(i);
    }
 cout<<t;
}
