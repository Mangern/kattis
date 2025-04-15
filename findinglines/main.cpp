#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

ll n, p;
ll x[mxN];
ll y[mxN];

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    if (n <= 2) {
        cout << "possible" << endl;
        return 0;
    }

    srand(time(NULL));

    ll goal = (n * p + 99)/100;
    for (int _ = 0; _ < 500; ++_) {
        int i = rand() % (n - 1);
        int j = i + 1 + rand() % (n - i - 1);

        ll cnt = 2;

        ll dy = y[j] - y[i];
        ll dx = x[j] - x[i];

        for (int k = 0; k < n; ++k) if (k != i && k != j) {
            if ((y[k] - y[i]) * dx == dy * (x[k] - x[i])) {
                ++cnt;
            }
        }

        if (cnt >= goal) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}
