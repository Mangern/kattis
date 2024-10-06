#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
template<typename t, size_t N>
using ar = array<t, N>;
using ii = ar<ll, 2>;
using vii = vector<ii>;
using vll = vector<ll>;

template<typename t>
istream& operator>>(istream& in, vector<t>& vec) {
    for (t& x : vec) {
        in >> x;
    }
    return in;
}

template<typename t>
ostream& operator<<(ostream& os, vector<t>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << " ";
    }
    return os;
}
#define all(v) begin(v), end(v)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (uint64_t)rng() % B;
}

template<typename t>
t min(const vector<t>& v) {
    return *min_element(all(v));
}

template<typename t>
t max(const vector<t>& v) {
    return *max_element(all(v));
}
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;

struct frac {
    ll num, den;

    frac() {
        this->num = 0;
        this->den = 1;
    }

    frac(ll n, ll d) {
        ll g = gcd(n,d);
        n /= g;
        d /= g;
        this->num = n;
        this->den = d;
    }

    frac operator+(const frac& other) const {
        return frac(num * other.den + den * other.num, den * other.den);
    }

    frac operator*(const frac& other) const {
        return frac(num * other.num, den * other.den);
    }

    void operator+=(const frac& other) {
        num = num * other.den + den * other.num;
        den *= other.den;
        ll g = gcd(num, den);
        num /= g;
        den /= g;
    }

    void operator-=(const frac& other) {
        num = num * other.den - den * other.num;
        den *= other.den;
        ll g = gcd(num, den);
        num /= g;
        den /= g;
    }

    bool operator<=(const frac& other) const {
        // a/b <= c/d
        // a * d <= c * b
        return num * other.den <= den * other.num;
    }
};

struct drink {
    string name;
    int strength;
    int size;
    ll cost;

    frac units() {
        if (size == 0) {
            return frac(strength, 1);
        } else if (size == 1) {
            return frac(strength, 2);
        } else {
            return frac(strength, 3);
        }
    }
};

struct state {
    ll spend;
    int drink_start;
    frac units;

    bool operator<(const state& other) const {
        if (spend != other.spend)return spend < other.spend;
        if (drink_start != other.drink_start)return drink_start < other.drink_start;
        if (units.num != other.units.num)return units.num < other.units.num;
        return units.den < other.units.den;
    }
};

state apply_drink(state st, drink dr) {
    st.spend += dr.cost;
    st.units += dr.units();
    return st;
}

state unapply_drink(state st, drink dr) {
    st.spend -= dr.cost;
    st.units -= dr.units();
    return st;
}

void testCase() {
    string ms;
    ll m;
    cin >> ms;
    m = stoll(ms.substr(0, ms.find('.'))) * 100 + stoll(ms.substr(ms.find('.')+1, ms.size()));
    int d;
    double ud;
    cin >> ud;
    frac u((ll)(ud * 10), 10);
    cin >> d;

    vector<drink> drinks(d);
    for (int i = 0; i < d; ++i) {
        cin >> drinks[i].name;
        cin >> drinks[i].strength;
        string sz;
        cin >> sz;
        drinks[i].size = sz.back() - '1';
        cin >> ms;
        drinks[i].cost = stoll(ms.substr(0, ms.find('.'))) * 100 + stoll(ms.substr(ms.find('.')+1, ms.size()));
    }

    map<state, int> vis;
    queue<state> q;
    state start{0, 0, frac()};
    vis.insert({start, -1});
    q.push(start);

    while (q.size()) {
        state fr = q.front();
        q.pop();

        if (fr.drink_start == d)continue;

        //cout << fr.spend << " " << fr.drink_start << " " << fr.units.num << "/" << fr.units.den << endl;

        state nxt1 = apply_drink(fr, drinks[fr.drink_start]);
        if (nxt1.spend <= m && fr.units <= u && !vis.count(nxt1)) {
            vis[nxt1] = 1;
            q.push(nxt1);
        }
        if (fr.drink_start < d) {
            state nxt2 = state{fr.spend, fr.drink_start + 1, fr.units};
            if (!vis.count(nxt2)) {
                vis[nxt2] = 0;
                q.push(nxt2);
            }
        }
    }

    state ptr{m, d, u};

    if (!vis.count(ptr)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    map<string,int> counts;
    while (vis[ptr] != -1) {
        int c = vis[ptr];
        if (c) {
            ++counts[drinks[ptr.drink_start].name];
            ptr = unapply_drink(ptr, drinks[ptr.drink_start]);
        } else {
            ptr.drink_start -= 1;
        }
    }
    for (auto [name, cnt] : counts) {
        cout << name << " " << cnt << endl;
    }
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 1;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
