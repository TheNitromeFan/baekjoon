#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r) >> 1)

int q, m, a[1001001], sz, t[4004004];
list<int> s[1001001];

void upd(int x, int node = 1, int l = 0, int r = m-1){
    if(x < l || r < x) return;
    if(l == r){
        t[node] = (s[x].empty() ? 0 : s[x].back());
        return;
    }
    upd(x, node*2, l, mid), upd(x, node*2+1, mid+1, r);
    t[node] = min(t[node*2], t[node*2+1]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> q >> m;

    if(m >= q){
        while(q--){
            int x; cin >> x;
            if(x == 1) cin >> x;
            else if(x == 3) cout << "-1\n";
        }
        return 0;
    }

    while(q--){
        int x; cin >> x;
        if(x == 1){
            ++sz;
            cin >> a[sz];
            a[sz] %= m;
            s[a[sz]].push_back(sz);
            upd(a[sz]);
        }
        if(x == 2 && sz){
            s[a[sz]].pop_back();
            upd(a[sz]);
            sz--;
        }
        if(x == 3){
            cout << (t[1] ? sz - t[1] + 1 : -1) << "\n";
        }
    }
}
