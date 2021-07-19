#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    vector<int> rev[n+1];
    vector<bool> vis(n+1);
    stack<int> s;
    vector<int> tmp;
    vector<vector<int>> scc;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    function<void(int)> dfs1 = [&](int x) {
        vis[x] = true;
        for (int nxt : adj[x]) {
            if (!vis[nxt])
                dfs1(nxt);
        }
        s.push(x);
    };

    function<void(int)> dfs2 = [&](int x) {
        vis[x] = true;
        for (int nxt : rev[x]) {
            if (!vis[nxt])
                dfs2(nxt);
        }
        tmp.push_back(x);
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs1(i);
    }

    vis = vector<bool>(n + 1);

    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (!vis[x]) {
            tmp.clear();
            dfs2(x);
            sort(begin(tmp), end(tmp));
            scc.push_back(tmp);
        }
    }
    
    sort(begin(scc), end(scc), [](auto l, auto r) {
        return l[0] < r[0];
    });
    cout << scc.size() << '\n';
    for (auto& components : scc) {
        for (int x : components) 
            cout << x << ' ';
        cout << "-1\n";
    }
}