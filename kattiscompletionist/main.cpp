#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double g;
    cin >> g;

    priority_queue<double, vector<double>, greater<double>> pq;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while (pq.size()) {
        ++ans;

        double s = 0.0;

        while (pq.size() && s < g - 1e-9) {
            s += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
}
