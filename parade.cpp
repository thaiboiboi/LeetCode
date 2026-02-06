#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n,m;
int cnt=0,ans=0;
priority_queue<iii, vector<iii>, less<iii> > pq;
int parent[1001], r[1001];

int find_set(int v)
{
    if(v==parent[v]) return v;
    parent[v]=find_set(parent[v]);
    return parent[v];
}

bool union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(r[a]==r[b]){
            parent[b]=a;
            r[a]++;
        }
        else if(r[a]>r[b]) parent[b]=a;
        else parent[a]=b;
        cnt++;
        return true;
    }
    return false;
}

int main()
{
    freopen("parade.inp","r",stdin);
    freopen("parade.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pq.push(iii(w,ii(u,v)));
    }

    for(int i=1;i<=n;i++) parent[i]=i;

    while(!pq.empty()){
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        int w=pq.top().first;
        //cout<<u<<" "<<v<<" "<<w<<endl;
        pq.pop();
        if(!union_sets(u,v)) ans+=w;
    }

    cout<<ans;
    return 0;
}
