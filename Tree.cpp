#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second

struct node {
    string data;
    node *left;
    node *right;
    node (){
        this->left=this->right=NULL;
    }
};

bool isleaf(node *x) {
    return (x->left==NULL&&x->right==NULL);
}

int tinh(node *x) {
    if (isleaf(x)) {
        return (stoi(x->data));
    }
    else {
        int b,c;
        b=tinh(x->left);
        if (x->right!=NULL) c=tinh(x->right);
        if (x->data=="abs") return abs(b);
        if (x->data=="max") return max(b,c);
        if (x->data=="min") return min(b,c);
    }
}

stack<node*> a;
string st;

int main() {
    //freopen("HaiDaySo.inp","r",stdin);
    //freopen("HaiDaySo.out","w",stdout);

    getline(cin,st);
    int i=(int)st.size()-1;
    while(i>=0) {
        if (isdigit(st[i])) {
            node *n=new node;
            string tmp="";
            while(isdigit(st[i])||st[i]=='-') tmp=st[i]+tmp, i--;
            n->data=tmp;
            a.push(n);
        }
        if (isalpha(st[i])) {
            string tmp="";
            tmp+=st[i-2];
            tmp+=st[i-1];
            tmp+=st[i];
            i-=3;
            node *n=new node;
            n->data=tmp;
            if (tmp=="max"||tmp=="min") {
                n->left=a.top();
                a.pop();
                n->right=a.top();
                a.pop();
            }
            if (tmp=="abs") {
                n->left=a.top();
                a.pop();
            }
            a.push(n);
        }
        i--;
    }
    cout << tinh(a.top());
    return 0;
}
