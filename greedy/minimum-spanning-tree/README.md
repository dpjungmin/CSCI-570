Any tree that covers all nodes of a graph is called a spanning tree.

A spanning tree with minimum total edge cost is a minimum spanning tree (MST).

## Kruskal's

```text
Sort all edges in increasing order of cost.
Add edges to T in their order as long as it does not create a cycle.
If it does, discard the edge.
```

```cpp
#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
    vector<int> p, rank;
    disjoint_set(int n) : p(n), rank(n, 1) {
        iota(begin(p), end(p), 0);
    }
    int find(int u) {
        if (u == p[u]) return u;
        return p[u] = find(p[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        p[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
};

struct edge {
    int from, to, cost;
    bool operator < (const edge& e) const {
        return cost < e.cost;
    }
};

/*
 * @n: number of nodes
 * @edges: all edges in the graph
 * returns the cost of the MST and the selected edges
 * cost is -1 if there is no spanning tree in the graph
 */
pair<int, vector<edge>> kruskal(int n, vector<vector<edge>> edges) {
    int mst = 0;
    vector<edge> selected;
    disjoint_set ds(n + 1);

    sort(begin(edges), end(edges));

    for (auto edge : edges) {
        auto [from, to, cost] = edge;
        if (ds.find(from) == ds.find(to))
            continue;
        ds.merge(from, to);
        mst += cost;
        selected.push_back(edge);
        if ((int)selected.size() == n - 1)
            break;
    }

    if ((int)selected.size() != n - 1)
        mst = -1;

    return {mst, selected};
}
```

When |E| = m, overall time complexity for Kruskal's algorithm is O(mlogm) since sorting is the most expensive operation.

## Prim's

```text
Similar to Dijkstra's algorithm,
start with a node set S (initially the root node) on which a minimum spanning tree has been constructed so far.
At each step, grow S by one node, adding the node v that minimizes the attachement cost.
```

```cpp
#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, cost;
    bool operator < (const edge& e) const {
        return cost > e.cost;
    }
};

/*
 * @n: number of nodes
 * @adj: adjacency list
 * returns the cost of the MST and the selected edges
 * cost is -1 if there is no spanning tree in the graph
 */
pair<int, vector<edge>> prim(int n, vector<vector<edge>> adj, int start) {
    int mst = 0;
    vector<bool> vis(n + 1);
    vector<edge> selected;
    priority_queue<edge> mnh;

    vis[start] = true;

    for (edge e : adj[start])
        mnh.push(e);

    while (!mnh.empty()) {
        edge e = mnh.top();
        mnh.pop();
        if (vis[e.to])
            continue;
        mst += e.cost;
        selected.push(e);
        if ((int)selected.size() == n - 1)
            break;
        for (edge e : adj[e.to]) {
            if (!vis[e.to])
                mnh.push(e);
        }
    }

    if ((int)selected.size() != n - 1)
        mst = -1;

    return {mst, selected};
}
```

When |V| = n and |E| = m, overall time complexity is the same as Dijkstra's, which is O(mlogn). However, in our implementation, we do not have a Decrease_Key operation in our min-heap. We are simply inserting all edges, thus; our implementation would take O(mlogm).
