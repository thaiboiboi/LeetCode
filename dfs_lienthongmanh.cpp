#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define maxN 1001
int n,m,u,v,component;
int number[maxN],low[maxN],dem;
bool a[maxN][maxN],f[maxN];
stack<int> s;

void nhap(){
	freopen("sconnect.inp","r",stdin);
    freopen("sconnect.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        a[u][v]=1;
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        number[i]=0;
    }
}
void Visit(int u){//tìm kiếm chiều sâu bắt đầu từ u
    dem++; number[u]=dem;
    low[u]=number[u];
    s.push(u); //đẩy u vào stack
    for(int v=1;v<=n;v++){//Xét các đỉnh v
        if (f[v]&&a[u][v]) //v kề u, v chưa bị loại bỏ
            if(number[v]!=0) //v đã thăm
                low[u]=min(low[u],number[v]);
			else{ //v chưa thăm
				Visit(v); //thăm v
				low[u]=min(low[u],low[v]);
			}
    }
    //Đến đây thì đỉnh u đã duyệt xong
    if (low[u]==number[u]){ //nếu u là chốt
        component++;
        printf("Component %d:",component);
        do{
            v=s.top(); //lấy đỉnh ra khỏi stack
            s.pop();
            printf("%d ",v); //in đỉnh
            f[v]=0; //loại đỉnh v khỏi đồ thị
        }while(v!=u);
        printf("\n");
    }
}
void xuly(){
	dem=0;
    component=0;
    for(int i=1;i<=n;i++)
        if(number[i]==0)
            Visit(i);
}
int main()
{
	nhap();
	xuly();
    return 0;
}






