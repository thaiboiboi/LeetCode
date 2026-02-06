#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define maxN 10001
#define inf 999999999
int n,m,s,u,v,num[maxN],dem;
int visit[300][300];

struct hinh
{
    int tren=0,duoi=0,trai=0,phai=0,gtt=0,gtd=0,gpt=0,gpd=0;
    char h;
};
hinh B[300][300];
void dfs(int u,int v){
    visit[u][v]=dem;
    cout<<u<<" "<<v<<" "<<dem<<endl;
    for(int i=u-1;i<=u+1;++i)
            if ((i>=1)&&(i<=n))
    {
        if (((B[u][v].duoi==B[i][v].tren)&&(i==u+1)&&(B[i][v].tren!=0))||((B[u][v].tren==B[i][v].duoi)&&(i==u-1)&&(B[i][v].duoi!=0)))
                 if (visit[i][v]==0)
              {
                 cout<<"1"<<endl;
                    dfs(i,v);
             }
       if (((B[u][v].gtd==B[i][v].gtt)&&(i==u+1)&&(B[i][v].gtt!=0))||((B[u][v].gtt==B[i][v].gtd)&&(i==u-1)&&(B[i][v].gtd!=0)))
                 if (visit[i][v]==0)
                  { cout<<"2"<<endl;
                    dfs(i,v);
             }
    if (((B[u][v].gpd==B[i][v].gpt)&&(i==u+1)&&(B[i][v].gpt!=0))||((B[u][v].gpt==B[i][v].gpd)&&(i==u-1)&&(B[i][v].gpd!=0)))
                 if (visit[i][v]==0)
             { cout<<"3"<<endl;
                    dfs(i,v);
             }
    if (((((B[u][v].duoi==B[i][v].trai)&&(B[i][v].trai!=0))||((B[u][v].duoi==B[i][v].phai)&&(B[i][v].phai!=0)))&&(i==u+1))||(((((B[u][v].tren==B[i][v].trai)&&(B[i][v].trai!=0))||((B[u][v].tren==B[i][v].phai)&&(B[i][v].phai!=0)))&&(i==u-1))))
                 if (visit[i][v]==0)
             { cout<<"4"<<endl;
                    dfs(i,v);
             }
    }
    for (int j=v-1;j<=v+1;++j)
        if ((j>=1)&&(j<=m))
    {
        if ((((B[u][v].phai==B[u][j].trai)&&(j==v+1)&&(B[u][j].trai!=0)))||((B[u][v].trai==B[u][j].phai)&&(j==v-1)&&(B[u][j].phai!=0)))
                 if (visit[u][j]==0)
                                { cout<<"5"<<endl;
                    dfs(u,j);
             }
       if (((B[u][v].gtd==B[u][j].gpd)&&(B[u][j].gpd!=0)&&(j==v-1))||((B[u][v].gpd==B[u][j].gtd)&&(B[u][j].gtd!=0)&&(j==v+1))||((B[u][v].gtt==B[u][j].gpt)&&(B[u][j].gpt!=0)&&(j==v-1))||((B[u][v].gpt==B[u][j].gtt)&&(B[u][j].gtt!=0)&&(j==v+1)))
                if (visit[u][j]==0)
              {
                  cout<<"6"<<endl;
                  dfs(u,j);
             }
    }
}

int main()
{
    freopen("trochoi.inp","r",stdin);
    freopen("trochoi.out","w",stdout);
    cin>>n>>m;
    char t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {cin>>B[i][j].h;
            t=B[i][j].h;
             if ((t=='A')||(t=='E')||(t=='F')||(t=='H')||(t=='J')||(t=='L'))
                 B[i][j].duoi=1;
                if ((t== 'A')||(t== 'E')||(t== 'F')||(t== 'H')||(t== 'J')||(t== 'L'))
                       B[i][j].duoi=1;
                 if ((t== 'C')||(t== 'E')||(t== 'F')||(t== 'G')||(t== 'I')||(t== 'K'))
                     B[i][j].tren=1;
                 if ((t== 'D')||(t== 'E')||(t== 'G')||(t== 'H')||(t== 'K')||(t== 'L'))
                    B[i][j].trai=1;
                 if ((t== 'B')||(t== 'F')||(t== 'G')||(t== 'H')||(t== 'I')||(t== 'J'))
                     B[i][j].phai=1;
                 if ((t== 'C')||(t== 'D')||(t== 'E')||(t== 'G')||(t== 'I')||(t== 'K')||(t== 'L'))
                       B[i][j].gtt=1;
                 if ((t== 'A')||(t== 'D')||(t== 'E')||(t== 'H')||(t== 'J')||(t== 'K')||(t== 'L'))
                      B[i][j].gtd=1;
                 if ((t== 'B')||(t== 'C')||(t== 'F')||(t== 'G')||(t== 'I')||(t== 'J')||(t== 'K'))
                     B[i][j].gpt=1;
                 if ((t== 'A')||(t== 'B')||(t== 'F')||(t== 'H')||(t== 'I')||(t== 'J')||(t== 'L'))
                      B[i][j].gpd=1;
             }

    for(int i=1;i<=n;++i)
        for (int j=1;j<=m;++j){
        visit[i][j]=0;    }
    dem=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
         if (visit[i][j]==0)
    {   ++dem;
        dfs(i,j);
    }
    cout<<dem;
    return 0;
}
