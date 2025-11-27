#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 3e5+5;
const ll INF = numeric_limits<ll>::max() / 4;

ll n, q;

// remaining capacity
ll rem[mxN];
// original capacity
ll cap[mxN];

ll par[mxN];
// for UF
ll rnk[mxN];
ll big[mxN];
// next greater
ll nxt[mxN];

ll find(ll i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}

void join(ll i, ll j) {
    i = find(i);
    j = find(j);

    // rank == height
    if (rnk[i] < rnk[j]) {
        par[i] = j;
        big[j] = max(big[j], big[i]);
    } else {
        par[j] = i;
        big[i] = max(big[i], big[j]);
        if (rnk[i] == rnk[j]) {
            // increase height
            ++rnk[i];
        }
    }
}

int main() {
    cin >> n >> q;

    for (int i = 0; i <= n; ++i) {
        par[i] = i;
        big[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> cap[i];
        rem[i] = cap[i];
    }
    cap[n] = rem[n] = INF;

    deque<int> dq;
    dq.push_back(n);

    for (int i = n - 1; i >= 0; --i) {
        while (dq.size() && cap[dq.front()] <= cap[i])dq.pop_front();
        assert(dq.size());
        nxt[i] = dq.front();
        dq.push_front(i);
    }

    while (q-->0) {
        char c;
        cin >> c;

        if (c == '?') {
            ll i;
            cin >> i, --i;

            cout << cap[i] - rem[i] << endl;
        } else {
            ll i, x;
            cin >> i >> x, --i;

            while (x>0) {
                ll p = big[find(i)];
                ll sub = min(x, rem[p]);
                rem[p] -= sub;
                x -= sub;

                if (rem[p] == 0) {
                    join(p, nxt[p]);
                }
            }
        }
    }
}
