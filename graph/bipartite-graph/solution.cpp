class Solution {
    const int RED = 0;
    const int BLUE = 1;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n);
        vector<int> color(n);
        bool result = true;
        
        auto bfs = [&](int i) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            color[i] = RED;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                int nxt_color = color[x] != RED ? RED : BLUE;
                for (int nxt : graph[x]) {
                    if (!vis[nxt]) {
                        q.push(nxt);
                        vis[nxt] = true;
                        color[nxt] = nxt_color;
                    } else if (color[nxt] != nxt_color) {
                        return false;
                    }
                }
            }
            return true;
        };
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                result = bfs(i);
                if (!result)
                    break;
            }
        }
        
        return result;
    }
};