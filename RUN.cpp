#include <bits/stdc++.h>
#define ll long long
#define inf 1e9
#define maxN 1000
#define maxM 1000
using namespace std;

int len=0,lenMin=inf,dMin=inf,i=1;
int w[maxN][maxN];
int x[maxN],xMin[maxN];
int c[maxN];
int D = 0, k,a,b,s,p,l,q,t;
int td[4]={1,-1,0,0};
int tc[4]={0,0,1,-1};

int n,m,u,v,si,sj,fi,fj,ki,kj;
int table[maxN][maxM];
int d[maxN][maxM];
bool mark[maxN][maxM];

struct node{
    int i,j,w;
    node(int i,int j,int w){
        this->i=i;
        this->j=j;
        this->w=w;
    }
};
bool operator>(const node &v1,const node &v2){
    return v1.w>v2.w;
}
bool check(int i,int j){
    return (i>=1&&i<=n&&j>=1&&j<=m);
}
int dijkstraBIEN(int si, int sj)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            mark[i][j]=false;
            d[i][j] = inf;
        }
    priority_queue<node, vector<node>, greater<node> > pq;
    d[si][sj] = 1;
    pq.push(node(si, sj, 1));
    while (!pq.empty()) {
        int ui = pq.top().i;
        int uj = pq.top().j;
        pq.pop();
        if (mark[ui][uj])
            continue;
        if (ui == 1 || ui == n || uj == 1 || uj == m) {
            return d[ui][uj] + 5 - 1;
        }
        mark[ui][uj] = true;

        for (int k = 0; k < 4; k++)
            if (table[ui + td[k]][uj + tc[k]]!=inf){
            int vi = ui + td[k];
            int vj = uj + tc[k];
            int w = table[vi][vj];
            if (d[vi][vj] > d[ui][uj] + w) {
                d[vi][vj] = d[ui][uj] + w;
                pq.push(node(vi, vj, d[vi][vj]));
            }
        }
    }
}
void dijkstra(int si, int sj){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            d[i][j]=inf;
            mark[i][j]=false;
        }
    priority_queue<node, vector<node>, greater<node>> pq;
    d[si][sj]=0;
    pq.push(node(si,sj,0));
    while(!pq.empty()){
        int ui=pq.top().i;
        int uj=pq.top().j;
        pq.pop();
        if (mark[ui][uj]) continue;
		if (ui==ki&&uj==kj) break;
		mark[ui][uj]=true;

        for(int k=0; k<4; k++){
            int vi=ui+td[k];
            int vj=uj+tc[k];
			int w=table[vi][vj];
            if (d[vi][vj]>d[ui][uj]+w){
                d[vi][vj]=d[ui][uj]+w;
                pq.push(node(vi,vj,d[vi][vj]));
            }
        }

    }
}
void checkHAL()
{
    D++;
    if (len+w[x[k-1]][x[0]]<lenMin)
    {
        lenMin=len+w[x[k-1]][x[0]];
    }
}

void hamilton(int x[maxN],int c[maxN],int i)
{
    int j;
    for (j=2;j<=k;j++)
    {
        if (c[j]==0&&w[x[i-1]][j]!=0&&len+dMin*(k-i+1)<lenMin)
        {
            x[i]=j;
            c[j]=1;
            len+=w[x[i-1]][j];
            if (i<k-1) hamilton(x,c,i+1);
            else if (w[x[i]][x[0]]!=0) checkHAL();

            c[j]=0;
            len-=w[x[i-1]][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("RUN.inp", "r", stdin);
    freopen("RUN.out", "w", stdout);
    cin >> n >> m >> p >> l >> t>>q;
    for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                if(ch == '.')
                {
                    table[i][j] = 1;
                }
                else if(ch == 'D')
                {
                    table[i][j] = l + 1;
                }
                else if(ch == 'C')
                {
                    table[i][j] = t + 1;
                }
                else if(ch == 'H')
                {
                    table[i][j] = q + 1;
                }
                else if(ch == 'S')
                {
                    si = i;
                    sj = j;
                    table[i][j] = 1;
                }
                else if(ch == 'K')
                {
                    ki=i;
                    kj=j;
                    table[i][j] = p + 1;
                }
                else table[i][j] = inf;
            }
    dijkstra(si,sj);
     w[1][2] = d[ki][kj];
        w[2][1] = w[1][2];
        dMin=min(dMin,w[2][1]);
        dijkstra(ki,kj);
        w[2][2] = d[ki][kj];
        dMin=min(dMin,w[2][2]);
        w[5][2] = dijkstraBIEN(ki,kj);
        w[2][5] = w[5][2];
        dMin=min(dMin,w[2][5]);
    w[5][1] = 1;
    w[1][5] = 1;
    dMin=min(dMin,w[1][5]);
    checkHAL();
    k = 5; x[0]=1;
    for (int i=0;i<=k;i++) c[i]=0;
    hamilton(x,c,1);
    cout << lenMin-1;
    return 0;
}
