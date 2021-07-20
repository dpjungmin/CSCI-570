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

    // recurrence formula
    function<int(int)> f;
    f = [&](int x) {
        if (x == 0) 
            return 0;
        int& ret = dp[x];
        if (ret != -1)  
            return ret;
        return ret = max(a[x].w + f(p[x]), f(x - 1));
    };

    cout << f(n);
}