#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int dist(const Point& p) const {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
       
    int n; cin >> n;
    vector<Point> px(n), py(n);

    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        px[i] = py[i] = {x, y};
    }
    
    sort(begin(px), end(px), [](auto l, auto r) {
        return make_pair(l.x, l.y) < make_pair(r.x, r.y);
    });
    sort(begin(py), end(py), [](auto l, auto r)  {
        return make_pair(l.y, l.x) < make_pair(r.y, r.x);
    });

    function<int(vector<Point>, int, int)> closest;
    closest = [&](vector<Point> y, int l, int r) {
        // base case
        if (r - l + 1 <= 3) {
            int ret = INT_MAX;
            for (int i = l; i < r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    ret = min(ret, px[i].dist(px[j]));
                }
            }
            return ret;
        }
        // divide
        int mid = (l + r) / 2;
        Point mid_point = px[mid];
        vector<Point> pyl, pyr;
        for (Point p : y) {
            if (p.x < mid_point.x || (p.x == mid_point.x && p.y < mid_point.y)) {
                pyl.push_back(p);
            } else {
                pyr.push_back(p);
            }
        }
        // conquer
        int left = closest(pyl, l, mid);
        int right = closest(pyr, mid + 1, r);
        // combine
        int ret = min(left, right); // delta
        vector<Point> tmp;
        for (Point p : y) {
            int dx = p.x - mid_point.x;
            if (dx * dx < ret) {
                tmp.push_back(p);
            }
        }
        int sz = tmp.size();
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                int dy = tmp[j].y - tmp[i].y;
                if (dy * dy >= ret) break;
                ret = min(ret, tmp[i].dist(tmp[j]));
            }
        }
        return ret;
    };

    cout << closest(py, 0, n - 1);
}