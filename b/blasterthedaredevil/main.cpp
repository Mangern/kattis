#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, int>> events;
    for (int i = 0; i < n; ++i) {
        double x, a, b;
        cin >> x >> a >> b;
        events.push_back({a/x, 1});
        events.push_back({b/x, -1});
    }

    int cur = 0;
    int ans = 0;

    sort(begin(events), end(events));

    for (auto [_, d] : events) {
        ans = max(ans, cur);
        cur += d;
    }
    cout << ans << endl;
}
