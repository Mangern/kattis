#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void testcase() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    ll sa = 0, sb = 0;

    for (auto& x : a) {
        cin >> x;
        sa += x;
    }
    for (auto& x : b) {
        cin >> x;
        sb += x;
    }

    int ans = 0;

    for (auto x : a) {
        int inc = 0;
        
        // (sa - x) / (n - 1) > sa / n
        // (sa - x) * n > sa * (n - 1)
        // sa * n - x * n > sa * n - sa
        // - x * n > - sa
        // x * n < sa
        //
        // (sb + x) / (m + 1) > sb / m
        // (sb + x) * m > sb * (m + 1)
        // sb * m + x * m > sb * m + sb
        // x * m > sb

        if (x * n < sa)++inc;
        if (x * m > sb)++inc;

        ans += (inc == 2);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t-->0) {
        testcase();
    }
}
