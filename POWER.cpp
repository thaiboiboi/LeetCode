#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
struct t{
    int a,b;
};
t C[100000001];
int dem()
{
    int d=0;
    for (int i=2; i<=floor(sqrt(n)); ++i)
    {
        double khaican=pow(n,(float)1/i);
        if (khaican-floor(khaican)==0)
        {
            ++d;
            C[d].a=(int)khaican;
            C[d].b=i;
        }
    }
    return d;
}
int main()
{
    freopen("POWER.inp","r",stdin);
    freopen("POWER.out","w",stdout);
    cin>>n;
    int d=dem();
    cout<<d<<endl;
    for (int i=1;i<=d;++i)
        cout<<C[i].a<<" "<<C[i].b<<endl;
    return 0;
}
