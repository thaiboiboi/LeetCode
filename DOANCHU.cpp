#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[100001];
string s;
vector<vector<string> > table(25);
int point[25];

int main()
{
    freopen("doanchu.inp","r",stdin);
    freopen("doanchu.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s;
        table[(int)(s[0])-97].push_back(s);
    }
    for(int i=0;i<25;i++){
        sort(table[i].begin(),table[i].end());
        //cout<<(char)(i+97)<<" : ";
        //for(int j=0;j<table[i].size();j++) cout<<table[i][j]<<" ";
        //cout<<endl;
    }
    memset(point,0,sizeof(point));
    for(int i=0;i<k;i++){
        char c;
        cin>>c;
        int t=(int)(c)-97;
        cout<<table[t][point[t]]<<endl;
        if(point[t]==table[t].size()-1) point[t]=0;
        else point[t]++;
    }
    return 0;
}
