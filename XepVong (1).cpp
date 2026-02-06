#include <iostream>
#include <bits/stdc++.h>

using namespace std;
double r[9],A[9];

void calc(int j)
{
    double x;
    for (int i=0;i<j;++i)
    {
        x=sqrt((A[i]+A[j])*(A[i]+A[j])-(A[i]-A[j])*(A[i]-A[j]))+r[i];
        r[j]=max(r[j],x);
    }
}
int main()
{
    freopen("Xepvong.inp","r",stdin);
    freopen("Xepvong.out","w",stdout);
    int n;
    while (cin>>n){
    for (int i=0;i<n;++i)
        cin>>A[i];
    sort(A,A+n);
    for (int i=0;i<n;++i)
        r[i]=A[i];
    auto mx =1e100;
    do
    {
        for (int i=1;i<n;++i)
            calc(i);
        auto tmp=0.0;
        for (int i=0;i<n;++i)
            tmp=max(tmp,r[i]+A[i]);
        mx=min(mx,tmp);
    }
    while (next_permutation(A,A+n));
    printf("%0.3f\n",mx);}
    return 0;
}
