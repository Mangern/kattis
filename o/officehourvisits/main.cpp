#include <bits/stdc++.h>
using namespace std;

int main() {
    using ii = pair<int,int>;

    int n;
    cin >> n;

    vector<ii> ints(n);

    for (auto &[e, s] : ints) cin >> s >> e;
    sort(begin(ints), end(ints));

    int le = 0;
    int ans = 0;
    for (auto [e, s] : ints) {
        if (s >= le) {
            ++ans;
            le = e;
        }
    }
    cout << ans << endl;
}
