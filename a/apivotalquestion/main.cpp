#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int large_lft = 0;
    multiset<int> rgt;
    for (auto x : a) rgt.insert(x);

    vector<int> ans;

    for (auto x : a) {
        rgt.erase(rgt.find(x));
        large_lft = max(large_lft, x);

        if (x >= large_lft && (rgt.empty() || x < *rgt.begin())) {
            ans.push_back(x);
        }
    }
    cout << ans.size();
    for (int i = 0; i < min(100, (int)ans.size()); ++i) {
        cout << ' ' << ans[i];
    }
    cout << endl;
}
