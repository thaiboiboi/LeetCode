#include <bits/stdc++.h>
#define maxN 40
#define inf INT_MAX
#define ll long long

using namespace std;

typedef pair<int,int> ii;

int td[4]= {1,-1,0,0},
           tc[4]= {0,0,1,-1};
int n,m,x,y;
char table[maxN][maxN];
int d[maxN][maxN],d2[maxN][maxN];
bool mark[maxN][maxN];

struct node
{
    int i,j,w;
    node(int i,int j,int w)
    {
        this->i=i;
        this->j=j;
        this->w=w;
    }
};

bool operator>(const node &v1, const node &v2)
{
    return v1.w>v2.w;
}

bool check (int i, int j)
{
    return (i>=1&&i<=n&&j>=1&&j<=n);
}

void dijkstra(int si,int sj)
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) d[i][j]=inf;

    priority_queue<node,vector<node>,greater<node>> pq;
    d[si][sj]=0;
    pq.push(node(si,sj,0));
    while(!pq.empty())
    {
        int ui=pq.top().i;
        int uj=pq.top().j;
        pq.pop();
        for (int k=0; k<4; k++)
        {
            int vi=ui+td[k];
            int vj=uj+tc[k];
            if (check(vi,vj))
            {
                int w;
                if (table[vi][vj]==table[ui][uj]) w=x;
                else w=y;
                if (d[vi][vj]>d[ui][uj]+w)
                {
                    d[vi][vj]=d[ui][uj]+w;
                    pq.push(node(vi,vj,d[vi][vj]));
                }
            }
        }
    }
}

int main()
{
    freopen("MAZE.INP","r",stdin);
    freopen("MAZE.OUT","w",stdout);

    cin>>n>>x>>y;

    int tmp;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            cin>>table[i][j];

    int res=0;
    for (int i1=1; i1<=n; ++i1)
    {
        for (int i2=1; i2<=n; ++i2)
        {
            dijkstra(i1,i2);
            for (int j1=i1; j1<=n; ++j1)
                for (int j2=i2; j2<=n; ++j2)
                    res=max(res,d[j1][j2]);
        }
    }

    cout<<res;
}
