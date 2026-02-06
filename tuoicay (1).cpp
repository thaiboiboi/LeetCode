#include <bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;
#define Nmax 300

int X[Nmax],Y[Nmax];//ma tran ke
int  DsX[Nmax]; // DsX[0..n] luu cac dinh trong chu trinh Hamilton
int  C[Nmax]; // Mang danh dau dinh da co trong mang DsX[0..n] hay chua
int n,m,k,s,d,dmin=40001; // So dinh cua do thi
int w[Nmax][Nmax];

void ToiUu()
{
     dmin=min(dmin,d+w[DsX[k]][DsX[0]]);
}

void Hamilton(int *X , int *C , int i){
for(int j=1; j<=k; ++j){

  if(w[ DsX[i-1] ] [j]!=0 && C[j]==0){
   DsX[i]=j;
   C[j]=1;
   d+=w[ DsX[i-1] ][j];

   if(i<k)
    Hamilton(X, C, i+1);
   else
        if(w[DsX[i]][DsX[0]])
         ToiUu();
   C[j]=0;
   d-=w[DsX[i-1]][j];
  }
}
}

int main(){

 freopen("tuoicay.INP", "r",stdin);
 freopen("tuoicay.out","w",stdout);
 cin>>n>>m>>k;
 s=k+1;
 for(int i=1; i<=k; ++i)
   cin>>X[i]>>Y[i];
 for (int i=1;i<k;++i)
    for (int j=i+1;j<=k;++j)
    {
     w[i][j]=abs(X[i]-X[j])+abs(Y[i]-Y[j]) ;
     w[j][i]=w[i][j];
    }
 DsX[0]=s;

 for (int i=1; i<=n;i++)
    C[i]=0;
 for (int i=1;i<=k;++i)
 {
     w[s][i]=min(X[i],min(Y[i],min(m-X[i]+1,n-Y[i]+1)));
     w[i][s]=w[s][i];
 }
 C[s]=1;
 Hamilton(X,C,1); // Thu tuc de quy quay tim va xuat tat ca chu trinh Hamilton bat dau tu dinh DsX[0]=v
 cout<<dmin;
 return 0;

}
