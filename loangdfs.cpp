#include <cstdio>
using namespace std;
#define maxN 1000
int td[4]={1,-1,0,0};
int tc[4]={0,0,1,-1};

int n,m,u,v;
int table[maxN][maxN];
bool check(int i,int j){
    return (i>=1&&i<=n&&j>=1&&j<=m);
}
void dfs(int ui, int uj){
    table[ui][uj]=2;
    for(int k=0;k<4;k++){
        int vi=ui+td[k];
        int vj=uj+tc[k];
        if (check(vi,vj)&&table[vi][vj]==0)
            dfs(vi,vj);
    }
}
int main()
{
    freopen("vd.inp","r",stdin);
    freopen("vd.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            table[i][j]=0;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&table[i][j]);
    int dem=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (table[i][j]==0){
                dem++;
                dfs(i,j);
            }
    printf("%d",dem);

    return 0;
}






