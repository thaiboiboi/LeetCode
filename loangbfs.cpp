#include <cstdio>
#include <queue>
using namespace std;
#define maxN 1000
#define maxM 1000
#define inf 999999999
int td[4]={1,-1,0,0};
int tc[4]={0,0,1,-1};

typedef pair<int,int> ii;
int n,m,u,v,si,sj,ti,tj;
int table[maxN][maxM], d[maxN][maxM];
bool check(int i,int j){
    return (i>=1&&i<=n&&j>=1&&j<=m);
}
int bfs(int si, int sj){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=inf;
    queue<ii> q;
    q.push(ii(si,sj)); d[si][sj]=0; table[si][sj]=5;
    while(!q.empty()){
        int ui=q.front().first;
        int uj=q.front().second;
        q.pop();
        if (table[ti][tj]==5) return d[ti][tj];
        for(int k=0;k<4;k++){
            int vi=ui+td[k];
            int vj=uj+tc[k];
            if (check(vi,vj)&&(table[vi][vj]==0||table[vi][vj]==4)){
                q.push(ii(vi,vj));
                d[vi][vj]=d[ui][uj]+1;
                table[vi][vj]=5;
            }
        }
    }
	return -1;
}

int main()
{
    freopen("vd.inp","r",stdin);
    freopen("vd.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            table[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&table[i][j]);
            if (table[i][j]==3){
                si=i; sj=j;
            }
            if (table[i][j]==4){
                ti=i; tj=j;
            }
        }
    printf("%d",bfs(si,sj));
    return 0;
}






