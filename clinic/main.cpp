#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;



unordered_map<string,ll> tim;

bool cmp(string a, string b) {
    if (tim[a] == tim[b])return a > b;
    return tim[a] < tim[b];
}

priority_queue<string, vector<string>, function<bool(string,string)>> pq(cmp);
unordered_set<string> rem;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    while (n-->0) {
        int q;
        cin >> q;
        if (q == 1) {
            ll t, s;
            string m;
            cin >> t >> m >> s;
            tim[m] = s - k * t;
            pq.push(m);
        } else if (q == 2) {
            ll t;
            cin >> t;

            while (pq.size() && rem.count(pq.top()))pq.pop();
            if (pq.empty()) {
                cout << "doctor takes a break" << endl;
            } else cout << pq.top() << endl, pq.pop();
        } else {
            ll t;
            string m;
            cin >> t >> m;
            rem.insert(m);
        }
    }

    return 0;
}
