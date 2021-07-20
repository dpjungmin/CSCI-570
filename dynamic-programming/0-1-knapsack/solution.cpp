#include <bits/stdc++.h>

using namespace std;

struct item {
    int w, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    vector<item> items(n);
    for (auto& [w, v] : items) 
        cin >> w >> v;

    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        auto [w, v] = items[i-1];
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= w)
                dp[i][j] = max(dp[i][j], dp[i-1][j-w] + v);
        }
    }
    
    cout << dp[n][k];
}