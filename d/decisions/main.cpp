#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int solve(vector<ii>& v, int l, int r, int bit) {
    if (l == r) return 0;
    // check if all in range are equal

    int mi = min_element(begin(v)+l, begin(v)+r)->first;
    int ma = max_element(begin(v)+l, begin(v)+r)->first;
    if (mi == ma) {
        return 1;
    }

    int idx = partition(begin(v)+l, begin(v)+r, [&](auto x) { return ((x.second >> bit)&1) == 0; }) - begin(v);
    int ret = 1;
    return 1 + solve(v, l, idx, bit+1) + solve(v, idx, r, bit+1);
}


int main() {
    int n;
    cin >> n;

    vector<ii> v(1<<n);

    for (auto &x : v)cin >> x.first;
    for (int i = 0; i < v.size(); ++i)v[i].second = i;

    int ans = solve(v, 0, 1<<n, 0);
    cout << ans << endl;
}
