#include <bits/stdc++.h>
#define inf 100000000
#include <iostream>

using namespace std;

int coinBUS[11],val[101];

int main()
{
    freopen("BUS.inp","r",stdin);
    freopen("BUS.out","w",stdout);

    int customersKM;

    for (int i=1;i<=10;++i)
            cin>>coinBUS[i];

    cin>>customersKM;
    for (int i=0;i<customersKM;++i)
        val[i+1]=inf;
    val[0]=0;
    for (int i=1;i<=customersKM;++i) {
            for (int j=1;j<=10;++j)
                if (i>=j)
                    if ( (val[i]==inf) || (val[i]>val[i-j]+coinBUS[j]))
                     val[i]=coinBUS[j]+val[i-j];
    }
        cout<<val[customersKM]<<endl;
    return 0;
}
