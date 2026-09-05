#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

int main() {
    int n;
    cin >> n;

    vector<ii> a(n);
    ll sl=0,sr=0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        sl += a[i].first;
        sr += a[i].second;
    }

    if (n % 2 != 0) {
        cout << "impossible" << endl;
        return 0;
    }
    if (sl % (n / 2) != 0 || sr % (n / 2) != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    ii goal = {sl / (n / 2), sr / (n / 2)};

    multiset<ii> have;
    for (int i = 0; i < n; ++i) {
        ii need = goal;
        need.first -= a[i].first;
        need.second -= a[i].second;

        if (have.count(need)) {
            have.erase(have.find(need));
        } else {
            have.insert(a[i]);
        }
    }
    if (have.size()) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
}
