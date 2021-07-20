# Dijkstra's Shortest Path Algorithm

## Implementation of Dijkstra's

```text
S = Null
Initialize priority queue Q with all nodes v where d(u) is the key value (all d(u)'s are INF except for s where d(s) = 0).
While S != V
    u = Extract_Min(Q)
    Add u to S
    For each vertex v adjacent to u
        If (d(v) > d(u) + w_uv)
            Decrease_Key(Q, v, d(v) + w_uv)
        Endif
    Endfor
Endwhile
```

```cpp
/*
 * @adj : adjacency list
 * @src : starting vertex
 * returns shortest distance from src to all vertices
 * and a pointer to the previous vertex in the shortest path
 */
pair<vector<int>, vector<int>> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    struct Node {
        int u, d;
        bool operator<(const Node& x) const {
            return d > x.d;
        }
    };
    const int INF = INT_MAX;

    int n = adj.size();
    vector<int> dist(n + 1, INF);
    vector<int> ptr(n + 1, -1);
    priority_queue<Node> mnh;

    dist[src] = 0;
    mnh.push({src, dist[src]});

    while (!mnh.empty()) {
        auto [u, d] = mnh.top();
        mnh.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                mnh.push({v, dist[v]});
                ptr[v] = u;
            }
        }
    }

    return {dist, ptr};
}
```

## Complexity Analysis

Using a min-heap, the time complexity is O(mlogn). However, in our implementation, we do not have a Decrease_Key operation. Thus, our implementation would take O(mlogm).
