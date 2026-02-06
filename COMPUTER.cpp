#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a1,a2,a3,b1,b2,b3, t=0;
void Hoplai(int &x, int &y)
{
  int tam=min(x,y);
  x-=tam;
  y-=tam;
  t+=tam;
}
int main()
{
    freopen("COMPUTER.inp","r",stdin);
    freopen("COMPUTER.out","w",stdout);
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    Hoplai(a1,b1); Hoplai(a2,b2); Hoplai(a3,b1); Hoplai(a3,b2); Hoplai(a3,b3); Hoplai(a1,b3); Hoplai(a2,b3);
    cout<<t;
    return 0;
}
