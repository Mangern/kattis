#include <iostream>
#include <array>
#include <set>
#include <cassert>

using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    int n;
    cin >> n;

    multiset<ii> st;

    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;

        if (t == "add") {
            ll e, g;
            cin >> e >> g;
            st.insert({e, g});
        } else {
            ll x;
            cin >> x;

            ll ans = 0;
            while (true) {
                auto it = st.upper_bound({x, 1000000});
                if (it == st.begin())break;
                --it;
                assert((*it)[0] <= x);
                ans += (*it)[1];
                x -= (*it)[0];
                st.erase(it);
            }
            cout << ans << endl;
        }
    }
}
