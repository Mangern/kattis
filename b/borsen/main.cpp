#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double q;
    cin >> q;

    vector<double> price(n);

    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }

    double coins = 100.0;
    double num = 0.0;
    double ans = 100.0;
    for (int i = 0; i < n; ++i) {
        double nc = price[i] * num - q;
        double nn = (coins - q) / price[i];

        coins = max(nc, coins);
        num = max(nn, num);
        ans = max(ans, coins);
    }
    cout << setprecision(10) << fixed << coins << endl;
}
