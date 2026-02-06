#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long> > vv;

void below(queue<long> q,vv &children,vector<long> indegree,vector<long> &c,long src)
{
    long res=0;
    while (!q.empty()){
        long u=q.front();
        q.pop();
        if (u==src) continue;
        res++;
        for (auto i=children[u].begin();i!=children[u].end();i++){
            if (--indegree[*i]==0) q.push(*i);
        }
    }
    c[src]=res;
}

void above(vv &parent,vector<long> &p,long src,long n){
    vector<bool> visited(n,false);
    queue<long> q;
    visited[src]=true;
    long res=0;
    q.push(src);
    while(!q.empty()){
        long u=q.front();
        q.pop();
        for (auto i=parent[u].begin();i!=parent[u].end();i++){
            if (!visited[*i]){
                res++;
                visited[*i]=true;
                q.push(*i);
            }
        }
    }
    p[src]=res;
}

int main()
{
    freopen("thangtien.inp","r",stdin);
    freopen("thangtien.out","w",stdout);
    ios::sync_with_stdio(false);
    long a,b,n,v,resA=0,resB=0,resC=0;
    cin>>a>>b>>n>>v;
    vv parent(n),children(n);
    vector<long> indegree(n,0);
    vector<long> p(n),c(n);
    queue<long> q;
    while (v--){
        long s,d;
        cin>>s>>d;
        parent[d].push_back(s);
        children[s].push_back(d);
        indegree[d]++;
    }
    for (long i=0;i<n;i++) if(!indegree[i]) q.push(i);
    for (long i=0;i<n;i++){
        below(q,children,indegree,c,i);
        above(parent,p,i,n);
    }
    for (long i=0;i<n;i++){
        if (c[i]<a) resA++;
        if (c[i]<b) resB++;
        if (p[i]>=b) resC++;
    }
    cout<<resA<<endl;
    cout<<resB<<endl;
    cout<<resC<<endl;
}
