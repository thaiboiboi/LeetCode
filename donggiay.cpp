#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   struct DC
   {
       int date,t,vt;
   };
   freopen("donggiay.inp","r",stdin);
   freopen("donggiay.out","w",stdout);
   int Test,dem=0;
   cin>>Test;
   while (++dem<=Test)
   {
       int n;
       cin>>n;
       DC A[n];
       for (int i=1;i<=n;++i)
       {
        cin>>A[i].date>>A[i].t;
        A[i].vt=i;
        }
       for (int i=1;i<n;++i)
         for (int j=i+1;j<=n;++j)
           if ((A[i].t*(A[i].date+A[j].date)+A[j].date*A[j].t)<(A[j].t*(A[i].date+A[j].date)+A[i].date*A[i].t))
                    swap(A[i],A[j]);
       for (int i=1;i<=n;++i)
         cout<<A[i].vt<<" ";
       cout<<endl;
   }
   return 0;
}
