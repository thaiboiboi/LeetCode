#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;

int check()
{
    if (n==1)
        return 1;
    else
      if (n==2)
          return 2;
    else
        if (n==3 || n==4)
           return 6;
           else
             return 3;
}
int main()
{
    freopen("Digits.inp","r",stdin);
    freopen("Digits.out","w",stdout);

    cin>>n;
    if (n<=5)
      cout<<check();
    else
    cout<<"9";
    return 0;
}
