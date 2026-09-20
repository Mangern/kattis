#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

struct node {
    double p;
    ll cnt;
    double elen;

    node(double p, ll cnt, double elen) : p{p}, cnt{cnt}, elen{elen} {}

};

int main() {
    int n;
    cin >> n;

    array<double, 4> prob;

    array<ll, 21> fac;
    fac[0] = 1;
    for (ll i = 1; i <= 20; ++i) {
        fac[i] = fac[i-1] * i;
    }

    for (int i = 0; i < 4; ++i) {
        cin >> prob[i];
    }

    using el = pair<double, node*>;
    priority_queue<el, vector<el>, greater<el>> pq;
    for (int n1 = 0; n1 <= n; ++n1) {
        for (int n2 = 0; n2 <= n - n1; ++n2) {
            for (int n3 = 0; n3 <= n - n1 - n2; ++n3) {
                int n4 = n - n1 - n2 - n3;
                ll cnt = fac[n] / fac[n1] / fac[n2] / fac[n3] / fac[n4];

                double p = pow(prob[0], n1) 
                         * pow(prob[1], n2)
                         * pow(prob[2], n3)
                         * pow(prob[3], n4);
                pq.push({p, new node(p, cnt, 0.0)});
            }
        }
    }

    while (pq.size()) {
        auto [p, n] = pq.top();

        if (n->cnt == 1) {
            pq.pop();
            if (!pq.size()) break;

            auto [p2, n2] = pq.top();


            double np = p + p2;
            double nlen = p / np * (1.0 + n->elen) + p2 / np * (1.0 + n2->elen);
            node* nw = new node(np, 1, nlen);
            if (!--n2->cnt) {
                pq.pop();
            }
            pq.push({nw->p, nw});
            continue;
        }
        node* nw = new node(2*p, n->cnt/2, 1.0 + n->elen);
        n->cnt -= nw->cnt*2;
        if (n->cnt == 0) {
            pq.pop();
        }
        pq.push({nw->p, nw});
    }

    auto [_, root] = pq.top();
    pq.pop();

    cout << setprecision(9) << fixed << root->elen << endl;
}
