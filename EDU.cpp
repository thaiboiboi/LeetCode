#include <bits/stdc++.h>

using namespace std;

#define pb push_back
int Fx[1000][1000];
int main()
{
 freopen("EDU.inp","r",stdin);
 freopen("EDU.out","w",stdout);
 int n,t,p;
 cin>>n>>t>>p;
 for(int j=p; j<=t; j++)
      Fx[1][j]=1;
 for(int i=2; i<=n; i++)
     for(int j=p*i; j<=t; j++)
         {for(int k=p; k<=j-(i-1)*p; k++)
          Fx[i][j]=Fx[i][j]+ Fx[i-1][j-k];}
 cout<<Fx[n][t];
}
