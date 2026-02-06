#include <bits/stdc++.h>

#define inf 99999

using namespace std;

int n, m, k, p, p0, u, v, w, CC;
int a[1111][1111], visited[1111];

void bfs(int s){
    queue<int> q;
    q.push(s); visited[s]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v=1;v<=n;v++){
            if (a[u][v]&&!visited[v])
            {
                q.push(v);
                visited[v]=1;
            }
        }
    }
}

int main()
{
    ifstream ip;
    ofstream op;
    ip.open("PIZZA.INP");
    op.open("PIZZA.OUT");

    ip>>n>>m>>k;

    p=inf;
    for (int i=1;i<=k;i++)
    {
        ip>>p0;
        p=min(p, p0);
    }

    while (m--)
    {
        ip>>u>>v>>w;
        if (w>=p)
            a[u][v]=1,
            a[v][u]=1;
    }

    for (int i=1;i<=n;i++)
    {
        if (!visited[i]){
            bfs(i);
            CC++;
        }
    }

    op<<CC<<endl;

    ip.close();
    op.close();

    return 0;
}
