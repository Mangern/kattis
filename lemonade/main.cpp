#include <iostream>
#include <set>
#include <map>
#include <array>

using namespace std;

using tup = array<int, 2>;

int main() {
    int n, m, a, b, c, d, e, f, v0;
    cin >> n >> m >> a >> b >> c >> d >> e >> f >> v0;

    map<int, tup> states = {{v0, {0, 0}}};

    int ans = 0;

    for (int i = 1; i <= m; ++i) {
        map<int, tup> nstates;

        for (const auto& [k, state] : states) {
            int l = (d * i + e * k) % f;
            int v = (a * i + b * k) % c + 1;
            int capn = state[0];
            int score = state[1];

            if (capn + v <= n) {
                ans = max(ans, score + l);
                if (capn + v < n) {
                    auto it = nstates.find(0);

                    if (it == nstates.end() || it->second[1] < score + l) {
                        nstates[0] = {capn+v, score+l};
                    }
                }
            }

            if (capn < n && score + (f - 1) * (m + 1 - i) > ans) {
                auto it = nstates.find(v);

                if (it == nstates.end() || it->second[1] < score) {
                    nstates[v] = {capn, score};
                }
            }
        }

        states = nstates;
    }

    cout << ans << endl;
}
