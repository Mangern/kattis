#include <bits/stdc++.h>
using namespace std;
using ll = long long;


unordered_set<ll> vis;
set<ll> ans;
ll lo, hi;
void search(const vector<ll> &ps, ll num) {
    if (vis.count(num)) return;
    if (num > hi) return;

    vis.insert(num);

    if (num >= lo) {
        ans.insert(num);
    }

    for (auto p : ps) {
        search(ps, num * p);
    }
}

int main() {
    for (;;) {
        ll n;
        cin >> n;

        if (!n) break;
        vector<ll> ps(n);
        for (auto &p : ps)cin >> p;

        cin >> lo >> hi;
        ans.clear();
        vis.clear();

        search(ps, 1);

        if (ans.empty()) {
            cout << "none" << endl;
            continue;
        }

        cout << *ans.begin();
        ans.erase(ans.begin());

        for (auto x : ans) {
            cout << "," << x;
        }
        cout << endl;
    }
    return 0;
}
