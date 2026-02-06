#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("tatdien.inp","r",stdin);
    freopen("tatdien.out","w",stdout);

    string st;
    while(cin >> st&&st!="end") {
        int kq=INT_MAX;
        vector<int> a(15,0);
        for(int i=1;i<=10;i++) {
            for(int j=1;j<=10;j++) {
                char c;
                cin>>c;
                if (c=='O') a[i]|=1<<j;
            }
        }
        for(int i=0;i<(1<<10);i++) {
            int sl=0;
            vector<int> b(a);
            for(int j=1;j<=10;j++) {
                if (i&1<<(j-1)) {
                    b[1]^=1<<j;
                    b[1]^=1<<(j-1);
                    b[1]^=1<<(j+1);
                    b[2]^=1<<j;
                    sl++;
                }
            }
            for(int j=2;j<=10;j++) {
                for(int k=1;k<=10;k++) {
                    if (b[j-1]&(1<<k)) {
                        b[j-1]^=1<<k;
                        b[j]^=1<<k;
                        b[j]^=1<<(k-1);
                        b[j]^=1<<(k+1);
                        b[j+1]^=1<<k;
                        sl++;
                    }
                }
            }
            b[10]&=~1; b[10]&=~(1<<11);
            if (b[10]==0) kq=min(kq,sl);
        }
        cout << st << ' ';
        if (kq>100) cout << -1;
        else cout << kq;
        cout << '\n';
    }
    return 0;
}
