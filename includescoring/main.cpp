#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct player {
    ll s, p, f, o;
    int idx;

    bool operator <(const player& other) const {
        if (s == other.s) {
            if (p == other.p) {
                return f < other.f;
            }
            return p < other.p;
        }
        else return s > other.s;
    }
};

bool equals(player p1, player p2) {
    return p1.s == p2.s && p1.p == p2.p && p1.f == p2.f;
}


int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    vector<player> P(n), S(n);
    vector<ll> score(n);

    int scoreTable[] = { 100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    for (int i = 0; i < n; i++) {
        cin >> P[i].s >> P[i].p >> P[i].f >> P[i].o;
        P[i].idx = i;
        S[i] = P[i];
    }
    sort(S.begin(), S.end());

    for (ll i = 0; i < n; ) {
        ll sum = 0;
        ll j;
        for (j = i; j < n; j++) {
            if (equals(S[i], S[j])) {
                if (j < 30)sum += scoreTable[j];
            }
            else break;
        }
        sum = (sum + j - i - 1) / (j - i);

        while (i < j) {
            score[S[i].idx] = sum + S[i].o;
            i++;
        }
    }

    for (player p : P) {
        cout << score[p.idx] << endl;
    }
    return 0;
}
