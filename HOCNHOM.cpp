#include <bits/stdc++.h>
#define maxN 1000
#define maxM 1000
#define inf 999999

using namespace std;

int td[4]={1,-1,0,0}, tc[4]={0,0,1,-1};
int n,m,u,v,si,sj,wait_time_an,wait_time_nam,ans,si_a,sj_a,si_n,sj_n;
char table[maxN][maxM];
int d[maxN][maxM];
bool mark[maxN][maxM];



struct node
{
        int i,j,w;
        node(int i, int j, int w)
        {
            this->i=i;
            this->j=j;
            this->w=w;
        }
};

bool operator>(const node &v1, const node &v2){
    return v1.w>v2.w;
}

bool check (int i, int j) {
    return (i>=1&&i<=n&&j>=1&&j<=m);
}

void dijkstra(int si,int sj)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            d[i][j]=inf;
            mark[i][j]=false;
        }

    priority_queue<node,vector<node>,greater<node>> pq;
    d[si][sj]=0;
    pq.push(node(si,sj,0));
    while(!pq.empty())
    {
        int ui=pq.top().i;
        int uj=pq.top().j;
        pq.pop();
        if (mark[ui][uj]) continue;
        mark[ui][uj]=true;

        for (int k=0;k<4;k++)
        {
            int vi=ui+td[k];
            int vj=uj+tc[k];
            if (table[vi][vj]!='#')
            {
                int w=1;
                if (table[vi][vj]=='N') w+=wait_time_nam;
                if (table[vi][vj]=='A') w+=wait_time_an;
                if (table[vi][vj]>='0'&&table[vi][vj]<='9') w+=table[vi][vj]-'0';
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
    ifstream ip;
    ofstream op;
    ip.open("HOCNHOM.INP");
    op.open("HOCNHOM.OUT");

    ip>>n>>m>>wait_time_an>>wait_time_nam;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            ip>>table[i][j];
            if (table[i][j]=='B'){
                si=i; sj=j;
            }
            if (table[i][j]=='A'){
                si_a=i; sj_a=j;
            }
            if (table[i][j]=='N'){
                si_n=i; sj_n=j;
            }
        }

    dijkstra(si,sj); ans+=d[si_a][sj_a];

    dijkstra(si_a,sj_a); ans+=d[si_n][sj_n];

    dijkstra(si_n,sj_n); ans+=d[si][sj];

    if (ans<inf) op<<ans; else op<<"NO";


    return 0;
}

