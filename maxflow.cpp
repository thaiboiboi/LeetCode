#include <iostream>
#include <cstdio>
#include <queue>
#define inf 1e9
#define	maxN 500
using namespace std;

int n,m,s,t,c[maxN][maxN],trace[maxN],f[maxN][maxN];

//Tìm đường tăng luồng P trên Gf, trả về true nếu tìm thấy
bool FindPath()
{
    for(int i=1;i<=n;++i)
		trace[i]=0;
    queue<int> Q; Q.push(s);
    trace[s]= n+1;
    while (!Q.empty())
    {
        int u=Q.front(); Q.pop();
        for (int v=1;v<=n;v++) //Xét các đỉnh v kề u
			if (!trace[v]&&c[u][v]>f[u][v]){ //Nếu v chưa thăm và (u,v) chưa bão hòa
				trace[v]=u;
				if (v==t) return true; //Đến được t thì thuật toán dừng
				Q.push(v);
			}
    }
    return false;
}

//Tăng luồng f dọc theo đường tăng luồng P
void IncFlow()
{
    int delta,u,v;
	delta=inf;
	v=t; //Duyệt đường tăng luồng từ t đến s
    do
    {
        u=trace[v]; //Xét đỉnh u thăm trước v
        delta=min(delta,c[u][v]-f[u][v]); //Tìm giá trị delta nhỏ nhất
        v=u;
    } while (v!=s);

	v=t; //Duyệt đường tăng luồng từ t đến s
    do
    {
        u=trace[v]; //Xét đỉnh u thăm trước v
        f[u][v]+=delta; //Tăng luồng (u,v)
		f[v][u]-=delta; //Giảm luồng (v,u)
        v=u;
    } while (v!=s);
}

int main()
{
    freopen("flow.inp","r",stdin);
    freopen("flow.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&s,&t);
	int u,v,w;
    while (m--)
    {
		scanf("%d %d %d",&u,&v,&w);
        c[u][v]+=w;
    }
    while (FindPath()) //Nếu tìm được đường đi s đến t
		IncFlow(); //Tăng luồng

	int maxflow=0;
    for (int i=1;i<n;++i)
		if (f[i][n]>0) maxflow+=f[i][n]; 
    printf("%d",maxflow);
}

