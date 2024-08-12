#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fi first
#define se second

const int N = 1e6 + 6;

map<int, int> d[N];
vector<int> g[N];
int sz[N], pos[N], mx[N], res[N], fin[N];

void dfs(int p, int u, int depth = 0)
{
    sz[u] = 1;
    for (auto &v : g[u])
    {
        if (v != p)
        {
            dfs(u, v, depth + 1);
            sz[u] += sz[v];
            pos[u] = (sz[v] > sz[pos[u]] ? v : pos[u]);
        }
    }
    if (pos[u])
    {
        mx[u] = mx[pos[u]], res[u] = res[pos[u]], pos[u] = pos[pos[u]];
    }
    else
    {
        mx[u] = 1, res[u] = depth, pos[u] = u;
    }
    d[pos[u]][depth]++;
    if (mx[u] == 1){
        res[u] = min(res[u], depth);
    }
    for (auto v : g[u])
    {
        if (v != p && pos[v] != pos[u])
        {
            // cout << "u v " << u << ' ' << v << endl;
            for (auto &item : d[pos[v]])
            {
                d[pos[u]][item.fi] += item.se;
                // cout << item.fi << ' ' << item.se << ' ' << d[pos[u]][item.fi] << endl;
                if (d[pos[u]][item.fi] > mx[u])
                {
                    mx[u] = d[pos[u]][item.fi];
                    res[u] = item.fi;
                }
                else if (d[pos[u]][item.fi] == mx[u])
                {
                    res[u] = min(res[u], item.fi);
                }
            }
        }
    }
    fin[u] = res[u] - depth;
}

signed main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 1);
    // for (int i = 1; i <= n; ++i)
    //     cout << mx[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; ++i)
    //     cout << res[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; ++i)
    //     cout << pos[i] << ' ';
    // cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << fin[i] << endl;

    return 0;
}

/* input

*/