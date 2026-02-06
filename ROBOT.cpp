#include <bits/stdc++.h>
#define maxN 1000
#define maxM 1000
#define inf 999999

using namespace std;

int td[4]={1,-1,0,0}, tc[4]={0,0,1,-1};
int n,m,u,v,si,sj,fi,fj,ans;
char table[maxN][maxM];
int d[maxN][maxM];
bool mark[maxN][maxM];

int deter_w(char a)
{
    if (a=='A') return 3;
    if (a=='B') return 5;
    if (a=='C') return 2;
    return 7;
}

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
    d[si][sj]=deter_w(table[si][sj]);
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
                int w;
                if (table[ui][uj]=='A'){
                    if (table[vi][vj]=='B'&&(k==1||k==2)) w=inf; else w=deter_w(table[vi][vj]);
                }
                if (table[ui][uj]=='B'){
                    if (table[vi][vj]=='A'&&(k==0||k==3)) w=inf; else w=deter_w(table[vi][vj]);
                }
                if (table[ui][uj]=='C'){
                    if (table[vi][vj]=='D'&&(k==1||k==3)) w=inf; else w=deter_w(table[vi][vj]);
                }
                if (table[ui][uj]=='D'){
                    if (table[vi][vj]=='C'&&(k==0||k==2)) w=inf; else w=deter_w(table[vi][vj]);
                }
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
    ip.open("ROBOT.INP");
    op.open("ROBOT.OUT");

    queue<pair<int,int>> coor_to_check;

    ip>>n>>m>>si>>sj>>fi>>fj;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            ip>>table[i][j];
            if (table[i][j]!='A'&&table[i][j]!='B'&&table[i][j]!='C'&&table[i][j]!='D') table[i][j]='#';
        }

    dijkstra(si,sj);

    op<<d[fi][fj];


    return 0;
}
