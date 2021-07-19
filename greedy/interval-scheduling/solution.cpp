#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (auto& [s, e] : intervals)
        cin >> s >> e;

    sort(begin(intervals), end(intervals), [](auto l, auto r) {
        return make_pair(l.second, l.first) < make_pair(r.second, r.first);
    });

    int ans = 0;
    int last = 0;

    for (auto [s, e] : intervals) {
        if (s >= last) {
            ans++;
            last = e;
        }
    }

    cout << ans;
}