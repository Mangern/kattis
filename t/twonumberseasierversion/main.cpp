#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, double> get_avg_med(const vector<ll> &a, int ex1 = -1, int ex2 = -1) {
    ll sum = 0;
    ll num = 0;
    int pj = -1;
    int j = 0;
    while (j == ex1 || j == ex2) ++j;

    for (int i = 0; i < a.size(); ++i) {
        if (i == ex1 || i == ex2 ) continue;
        sum += a[i];
        num += 1;

        if (!(num & 1)) {
            pj = j;
            for (;;) {
                ++j;
                if (j == ex1 || j == ex2) continue;
                break;
            }
        }
    }
    double med;

    if (num & 1) med = a[j];
    else med = double(a[j] + a[pj]) / 2.0;

    if (sum % num != 0) return {numeric_limits<ll>::max() / 8, 0.0};
    ll avg = sum / num;
    return {avg, med};
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(begin(a), end(a));

    ll adiff;
    cin >> adiff;

    double mdiff;
    cin >> mdiff;

    auto [a_old, m_old] = get_avg_med(a);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [a_new, m_new] = get_avg_med(a, i, j);
            if (a_old + adiff == a_new && m_old + mdiff == m_new) {
                cout << a[i] << " " << a[j] << endl;
            }
        }
    }


}
