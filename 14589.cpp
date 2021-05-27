#include <bits/stdc++.h>
using namespace std;

struct seg
{
    int l, r, i;
    bool operator <(const seg& a) const
    {
        return l != a.l ? l < a.l : r < a.r;
    }
};

seg arr[150010];
int idx[150010];

bool adj(int x, int y)
{
    return !(arr[x].r < arr[y].l || arr[y].r < arr[x].l);
}

pair<int, int> rmx[150010];
int nex[150010][19];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        arr[i] = { l, r, i };
    }

    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        idx[arr[i].i] = i;

    rmx[0] = { arr[0].r, 0 };
    for(int i = 1; i < n; i++)
        rmx[i] = max(rmx[i - 1], { arr[i].r, i });

    for(int i = 0; i < n; i++)
    {
        seg t = { arr[i].r, (int)1e9, -1 };
        nex[i][0] = rmx[upper_bound(arr, arr + n, t) - arr - 1].second;
    }

    for(int t = 1; t < 19; t++)
        for(int i = 0; i < n; i++)
            nex[i][t] = nex[nex[i][t - 1]][t - 1];

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        int a = idx[x - 1];
        int b = idx[y - 1];
        if(a > b)
            swap(a, b);

        if(adj(a, b))
        {
            puts("1");
            continue;
        }

        if(arr[nex[a][18]].r < arr[b].l)
        {
            puts("-1");
            continue;
        }

        int c = a;
        int r = 0;
        for(int t = 18; t >= 0; t--)
        {
            if(arr[nex[c][t]].r < arr[b].l)
            {
                r += 1 << t;
                c = nex[c][t];
            }
        }

        if(adj(c, b))
            r += 1;
        else
            r += 2;

        printf("%d\n", r);
    }

    return 0;
}

