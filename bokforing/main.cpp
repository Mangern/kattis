#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 2e5+5;

ll front, back;
ll arr[1000005];
ll tim[1000005];
ll setx[mxN];
ll seti[mxN];
ll curw = 0;

void push(ll i, ll x) {
    seti[back] = i;
    setx[back++] = x;

}

void clear() {
    back = 0;
    front = 0;
}

bool has() {
    return back>front;
}

ii pop() {
    ll reti = seti[front];
    ll retx = setx[front];
    ++front;
    return {reti, retx};
}

int main() {
    ll n, q;
    cin >> n >> q;
    ll t = 0;
    while (q-->0) {
        string s;
        cin >> s;

        if (s == "SET") {
            ll i, x;
            cin >> i >> x;
            t++;
            push(i, x);
        } else if (s == "RESTART") {
            cin >> curw;
            t++;
            clear();
        } else {
            while (has()) {
                auto [i, x] = pop();
                arr[i] = x;
                tim[i] = t;
            }

            ll i;
            cin >> i;

            if (tim[i] < t)arr[i] = curw;

            cout << arr[i] << '\n';
        }
    }
}
