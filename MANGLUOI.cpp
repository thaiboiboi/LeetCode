#include <iostream>
#include <bits/stdc++.h>
#define fi "MANGLUOI.inp"
#define fo "MANGLUOI.out"
using namespace std;
int n,m,k,dem=0;
vector<int> a[10000];
int visit[10000]={0};

void dfs(int u){
    visit[u]=dem;
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if (visit[v]==0)
            dfs(v);
    }
}
int main()
{
   freopen(fi,"r",stdin);
   freopen(fo,"w",stdout);
   cin>>n>>m>>k;
   int t1,t2;
   for (int i=0;i<m;++i)
   {
     cin>>t1>>t2;
     a[t1].push_back(t2);
     a[t2].push_back(t1);
   }
   /*for (int i=0;i<n;++i)
       visit[i]=0;*/
   for (int i=0;i<n;++i)
     if (visit[i]==0)
     {
         dem++;
         dfs(i);
     }
   for (int i=0;i<k;++i)
   {
       cin>>t1>>t2;
       if (visit[t1]==visit[t2])
          cout<<"Yes"<<endl;
       else
          cout<<"No"<<endl;
   }
}
