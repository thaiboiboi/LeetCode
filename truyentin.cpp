#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define maxN 1001
int n,m,u,v;
int number[maxN],low[maxN],parent[maxN],dem;
bool a[maxN][maxN];

void readfile() {
	freopen("truyentin.inp","r",stdin);
    freopen("truyentin.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&u,&v);
        a[u][v]=1;
		a[v][u]=1;
    }
}

void Visit(int u) {
    number[u]=++dem;
    low[u]=n+1;
    for(int v=1;v<=n;v++) {
        if(a[u][v]) {
			a[v][u]=0;
			if(parent[v]==0) {
				parent[v]=u;
				Visit(v);
				low[u]=min(low[u],low[v]);
			} else low[u]=min(low[u],number[v]);
		}

    }
}
void solve() {
	dem=0;
	for(int u=1;u<=n;u++)
		parent[u]=0;
	for(int u=1;u<=n;u++)
		if(parent[u]==0) {
			parent[u]=-1;
			Visit(u);
		}
}

void printresult() {
	int u,v, dem2 = 0;
	int nchildren[maxN];
	bool isArticulation[maxN];
	dem = 0;
	for(int v=1;v<=n;v++) {
		u=parent[v];
		if (u!=-1&&low[v]>=number[v]) dem++;
	}
	for(int v=1;v<=n;v++) nchildren[v]=0;
	for(int v=1;v<=n;v++) {
		u=parent[v];
		if (u!=-1) nchildren[u]++;
	}
	for(int u=1;u<=n;u++)
		isArticulation[u]=(parent[u]==-1 && nchildren[u]>=2);
	for(int v=1;v<=n;v++) {
		u=parent[v];
		if (u!=-1 && parent[u]!=-1)
			if (low[v]>=number[u])
				isArticulation[u]=1;
	}
	for(int u=1;u<=n;u++)
		if (isArticulation[u]) dem2++;
    printf("%d %d", dem, dem2);
}


int main() {
	readfile();
    solve();
	printresult();
    return 0;
}
