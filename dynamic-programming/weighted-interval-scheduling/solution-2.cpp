#include <bits/stdc++.h>

using namespace std;

struct Schedule {
    int s, e, w;
    bool operator<(const Schedule& x) const {
        return e < x.e;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
       
    int n; 
    cin >> n;
    // a[i] = ith request (start time, end time, weight)
    vector<Schedule> a(n + 1); 
    for (int i = 1; i <= n; i++) 
        cin >> a[i].s >> a[i].e >> a[i].w;
    // p[i] = the longest request that is before and disjoint with the ith request
    // p[i] is `0` if there is no such compatible request
    // dp[i] = optimal weight for requests [1..i]
    vector<int> p(n + 1), dp(n + 1, -1);

    // sort by end time
    sort(begin(a), end(a));

    // precompute p
    p[0] = 0;
    for (int i = n; i >= 1; i--) {
        int l = 1, r = i - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m].e <= a[i].s) {
                l = m + 1;
                p[i] = m;
            } else {
                r = m - 1;
            }
        }
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], a[i].w + dp[p[i]]);
    }
    cout << dp[n];
}