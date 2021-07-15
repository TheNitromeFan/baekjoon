#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

struct MF {
    struct E {
        // to, 사람수, 도로 진입시각, 통과시간
        int t, c, st, tc;
        E *rev;
        E(int t, int c, int st, int tc) : t(t), c(c), st(st), tc(tc) {}
    };
    int n, s, k, limit;
    vector<vector<E *>> g;
    vector<int> c;
    vector<pii> f;
    MF(int n, int s, int k) : n(n), s(s), k(k) {
        g.resize(n);
        c.resize(n);
        f.resize(n);
    }
    void init(int x, int y) {
        n = x;
        limit = y;
        for (int i = 0; i < n; i++)
            g[i].clear();
        g[k].clear();
    }
    void aE(int u, int v, int w, int st, int tc) {
        E *ori = new E(v, w, st, tc);
        E *rev = new E(u, 0, st, tc);
        ori->rev = rev;
        rev->rev = ori;
        g[u].push_back(ori);
        g[v].push_back(rev);
    }
    int bfs(int tl) {
        for (int i = 0; i < n; i++) {
            c[i] = -1;
            f[i] = { -1,-1 };
        }
        c[k] = -1;
        f[k] = { -1,-1 };
        queue<int> q;
        q.push(s);
        c[s] = tl;
        while (q.size()) {
            int x = q.front();
            q.pop();
            if (c[k] >= 0) break;
            for (int i = 0; i < g[x].size(); i++) {
                if (c[x] + g[x][i]->tc <= limit && c[x] == g[x][i]->st && c[g[x][i]->t] == -1 && g[x][i]->c > 0) {
                    q.push(g[x][i]->t);
                    c[g[x][i]->t] = c[x] + g[x][i]->tc;
                    f[g[x][i]->t] = { x,i };
                }
            }
        }
        if (c[k] == -1) return 0;
        int x = k;
        int co = g[f[x].first][f[x].second]->c;
        while (f[x].first != -1) {
            co = min(co, g[f[x].first][f[x].second]->c);
            x = f[x].first;
        }
        x = k;
        while (f[x].first != -1) {
            if (f[x].first == 0) {
                for (auto i : g[0]) {
                    i->c -= co;
                    i->rev->c += co;
                }
            }
            else {
                E *e = g[f[x].first][f[x].second];
                e->c -= co;
                e->rev->c += co;
            }
            x = f[x].first;
        }
        return co;
    }
    int flow() {
        int ans = 0;
        for (int i = 0; i < limit; i++) {
            while (1) {
                int res = bfs(i);
                if (!res) break;
                ans += res;
            }
        }
        return ans;
    }
};


int main() {
    int tc;
    scanf("%d", &tc);
    MF mf = MF(1002, 0, 1001);
    while (tc--) {
        int n, i, g, s, m;
        scanf("%d%d%d%d%d", &n, &i, &g, &s, &m);
        mf.init(n + 2, s);
        for (int j = 0; j <= s; j++)
            mf.aE(mf.s, i, g, j, 0);
        while (m--) {
            scanf("%d", &n);
            for (int j = 0; j <= s; j++)
                mf.aE(n, mf.k, 101, j, 0);
        }
        scanf("%d", &m);
        int a, b, p, t;
        while (m--) {
            scanf("%d%d%d%d", &a, &b, &p, &t);
            for (int j = 0; j <= s; j++)
                mf.aE(a, b, p, j, t);
        }
        printf("%d\n", mf.flow());
    }
    return 0;
}

