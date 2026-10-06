#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using ll = long long;

#define all(v) begin(v), end(v)

const int mxN = 1e5+5;

struct Frac {
    ll num;
    ll den;
};

static inline bool operator<(const Frac& a, const Frac& b) {
    return a.num * b.den < a.den * b.num;
}

ll n;
ll b[mxN];

struct State {
    Frac W;
    ll cnt;

    bool operator<(const State& other) const {
        return W < other.W;
    }
};

int main() {
    scanf("%lld", &n);

    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &b[i]);
    }

    vector<ll> ub(b, b+n);
    sort(all(ub));
    ub.erase(unique(all(ub)), end(ub));

    ll m = ub.size();

    vector<ll> cnt(m, 0);
    for (ll i = 0; i < n; ++i) {
        ll idx = lower_bound(all(ub), b[i]) - begin(ub);
        ++cnt[idx];
    }

    priority_queue<State> pq;
    ll delta = n;

    for (int i = 0; i < m; ++i) {
        Frac pt_here{ub[i], 1};
        pq.push({pt_here, cnt[i]});
    }

    Frac prev_W = pq.top().W;
    double prev_f = 0.0;
    for (int i = 0; i < n; ++i) {
        ll ct = (b[i] * prev_W.den + prev_W.num - 1) / prev_W.num;
        prev_f += ct;
        prev_f += (double)prev_W.num / (double)prev_W.den * ct - b[i];
    }

    double best_f = prev_f;
    Frac best_W = prev_W;

    for (;;) {
        auto [W, cnt] = pq.top();
        pq.pop();

        double next_f = prev_f - (double)delta * (prev_W.num * W.den - W.num * prev_W.den) / (double)(prev_W.den * W.den);

        if (next_f < best_f) {
            best_f = next_f;
            best_W = W;
        }

        Frac next_W = W;
        ++next_W.den;

        delta += cnt;
        next_f += (double)(cnt * (W.num + W.den)) / (double)W.den;

        pq.push({next_W, cnt});

        prev_W = W;
        prev_f = next_f;

        if (delta > best_f) {
            break;
        }
    }

    best_W.num += best_W.den;
    ll g = __gcd(best_W.num, best_W.den);
    cout << best_W.num/g << '/' << best_W.den/g << endl;
}
