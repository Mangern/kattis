#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

struct evt {
    ll u, r, t;
    bool isj = 0;

    bool operator<(const evt& other) const {
        if (t != other.t)return t > other.t;
        return isj;
    }
};
priority_queue<evt> qs[10];
ll ready[10];
ll ju[10];
ll jr[10];
ll jim[10];

int main() {

    for (int i = 0; i < 10; ++i) {
        ready[i] = -10000000;
    }

    for (int i = 0; i < 10; ++i) {
        cin >> ju[i] >> jr[i];
    }
    qs[0].push(evt{
        .u = ju[0],
        .r = jr[0],
        .t = 0,
        .isj = 1
    });

    for (int i = 0; i < 10; ++i) {
        ll u, r, t;
        cin >> u >> r >> t;

        qs[i].push(evt{
            .u = u,
            .r = r,
            .t = t,
            .isj = 0
        });
    }

    ll ans = 0;

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 10; ++i) {
            //cout << k << " " << i << endl;
            int cnt =0;
            while (true) {
                auto e = qs[i].top();
                qs[i].pop();

                if (e.isj) {
                    ll start = max(e.t, ready[i]);
                    ans = start + e.u;
                    ready[i] = start + e.u;
                    int nxt = (i+1)%10;
                    qs[nxt].push(evt{
                        .u = ju[nxt],
                        .r = jr[nxt],
                        .t = start + e.u + e.r,
                        .isj = 1
                    });
                    jim[nxt] = start + e.u + e.r;
                    break;
                }

                ll start = max(e.t, ready[i]);
                // start + z * (e.u + e.r) < jim[i]
                // z < (jim[i] - start) / (e.u + e.r)
                ll z = (jim[i] - start + e.u + e.r - 1) / (e.u + e.r) - 1;
                if (z > 0) {
                    ready[i] = start + z * (e.u + e.r) - e.r;
                    qs[i].push(evt{
                        .u = e.u,
                        .r = e.r,
                        .t = start + z * (e.u + e.r),
                        .isj = 0
                    });
                } else {
                    ready[i] = start + e.u;
                    qs[i].push(evt{
                        .u = e.u,
                        .r = e.r,
                        .t = start + e.u + e.r,
                        .isj = 0
                    });
                }
            }
        }
    }

    cout << ans << endl;
}
