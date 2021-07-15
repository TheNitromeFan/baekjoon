#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
struct hopcroft_karp {
    int n;
    vector<int> a, b, dist, match, work;
    vector<vector<int>> vt;
    hopcroft_karp(int n) :n(n) {
        a.assign(n + 1, -1);
        b.assign(n + 1, -1);
        dist.assign(n + 1, 0);
        match.assign(n + 1, 0);
        vt.resize(n + 1);
    }
    void addEdge(int x, int y) {
        vt[x].push_back(y);
    }
    void bfs() {
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            if (!match[i]) {
                dist[i] = 0;
                qu.push(i);
            }
            else
                dist[i] = INF;
        }
        while (qu.size()) {
            int here = qu.front();
            qu.pop();
            for (auto there : vt[here]) {
                if (b[there] != -1 && dist[b[there]] == INF) {
                    dist[b[there]] = dist[here] + 1;
                    qu.push(b[there]);
                }
            }
        }
    }
    bool dfs(int here) {
        for (int &i = work[here]; i < vt[here].size(); i++) {
            int there = vt[here][i];
            if (b[there] == -1 || dist[b[there]] == dist[here] + 1 && dfs(b[there])) {
                match[here] = true;
                a[here] = there;
                b[there] = here;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int ret = 0;
        while (1) {
            work.assign(n + 1, 0);
            bfs();
            int flow = 0;
            for (int i = 1; i <= n; i++)
                if (!match[i] && dfs(i))flow++;
            if (!flow)break;
            ret += flow;
        }
        return ret;
    }
};
int n, x, y, z, w;
vector<vector<pair<int, int>>> v;
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &x, &y, &z, &w);
        v[i].push_back({ x,y });
        v[i].push_back({ z,w });
    }
    int lo = 0;
    int hi = 2999999;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        hopcroft_karp hk(2 * n);
        for (int i = 1; i <= n; i++) {
            for (auto x : v[i]) {
                if (mid >= x.second)
                    hk.addEdge(i, x.first);
            }
        }
        if (hk.solve() == n)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n", lo);
    return 0;
}
