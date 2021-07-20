class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        
        function<pair<int, int>(int, int)> go;
        go = [&](int l, int r) -> pair<int, int> {
            // base case
            if (l == r) {
                int x = prices[l];
                return {x, x};
            }
            // divide: O(1)
            int mid = (l + r) / 2;
            // conquer: O(1)
            auto [lmn, lmx] = go(l, mid);
            auto [rmn, rmx] = go(mid + 1, r);
            // combine: O(1)
            ans = max(ans, rmx - lmn);
            return {min(lmn, rmn), max(lmx, rmx)};
        };
        
        go(0, n - 1);
        
        return ans;
    }
};