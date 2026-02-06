#include <bits/stdc++.h>
using namespace std;

int t,n;
char o;
vector<vector<int> > adj(501);
int match[500];
bool seen[500];

struct node
{
    int st,a,b,c,d;
    node(int st,int a,int b,int c,int d)
    {
        this->st=st;
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
    }
};

vector<node> place;

void Init()
{
    for(int i=0;i<n;i++) adj[i].clear();
    place.clear();
    memset(match,-1,sizeof(match));
}

bool BPM(int u)
{
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!seen[v]){
            seen[v]=true;
            if(match[v]<0||BPM(v)){
                match[u]=v;
                return true;
            }
        }
    }
    return false;
}

int maxBPM()
{
    int ans=0;
    for(int u=0;u<n;u++){
        memset(seen,false,sizeof(seen));
        if(BPM(u))
            ans++;
    }
    return ans;
}

int main()
{
    freopen("taxi.inp","r",stdin);
    freopen("taxi.out","w",stdout);
    cin>>t;
    while(t--){
        Init();
        cin>>n;
        for(int i=1;i<=n;i++){
            int st,a,b,c,d,hour,minute;
            cin>>hour; cin>>o; cin>>minute; st=hour*60+minute;
            cin>>a>>b>>c>>d;
            place.push_back(node(st,a,b,c,d));
            //cout<<st<<endl;
        }
        for(int u=0;u<n-1;u++){
            for(int v=u+1;v<n;v++){
                if( abs(place[u].c - place[v].a) + abs(place[u].d - place[v].b) + abs(place[u].a - place[u].c) + abs(place[u].b - place[u].d) + place[u].st  < place[v].st ){
                    //cout<<abs(place[u].c - place[v].a) + abs(place[u].d - place[v].b) + abs(place[u].a - place[u].c) + abs(place[u].b - place[u].d) + place[u].st<<endl;
                    adj[u].push_back(v);
                }
            }
        }
        cout<<n-maxBPM()<<endl;
        //for(int i=0;i<n;i++){ cout<<i<<" : "; for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" "; cout<<endl; }
    }
    return 0;
}
