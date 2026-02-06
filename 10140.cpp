#include "stdio.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int LIM = 31622;
int a[100000];
vector<int> primes;
int mark[100000];
void Sieve()
{
vector<bool> notPrime(LIM + 2);

for (int i = 2; i <= LIM; ++i)

if (!notPrime[i])
{

primes.push_back(i);

for (int j = i * i; j <= LIM; j += i)

    notPrime[j] = true;

}

}

int FirstMul(int x, int l)

{

if (x >= l)
    return x * 2;
return l / x * x + (bool) (l % x) * x;
}
void Solve(int l, int r)
{
fill(mark, mark + (r - l + 1), 0);
for (int x : primes)
{
for (int i = FirstMul(x, l); i <= r; i += x)
    mark[i - l] = 1;
}
}
int main()
{
    freopen("10140.inp","r",stdin);
    freopen("10140.out","w",stdout);
    Sieve();
    int l,u;
    while(cin>>l>>u)
    {
        Solve(l,u);
        int d=0;
        int k=l;
        while(k<=u)
        {
        if (mark[k-1]==0)
                {
                   a[d]=k;
                   cout<<a[d]<<" ";
                   d++;
                }
        k++;
        }
        int mmax=0;
        int mmin=2147483647;
        int tam,x,y,o,p;
        for (int i=0;i<=d-1;i++)
        {
            tam=a[i+1]-a[i];
            if (tam<mmin)
            {
                x=i;
                y=i+1;
                mmin=tam;
            }
            if (tam>mmax)
            {
                o=i;
                p=i+1;
                mmax=tam;
            }
        }
        /*cout<<x<<" "<<y<<" "<<mmin<<" "<<o<<" "<<p<<" "<<mmax<<endl;*/
    }
    return 0;
}
