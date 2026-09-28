#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum Color {
    ORANGE = 0,
    GRAY   = 1,
    RED = 2
};

struct State {
    int o;
    int g;
    int r;

    ll key() const {
        return (ll)o | ((ll)g << 20) | ((ll)r << 40);
    }
};

bool is_solved(State s) {
    for (int i = 0; i < 10; ++i) {
        if (((s.o >> (2*i)) & 3) != ORANGE) return false;
        if (((s.g >> (2*i)) & 3) != GRAY) return false;
        if (((s.r >> (2*i)) & 3) != RED) return false;
    }
    return true;
}

int str_to_bits(const string& s) {
    int bits = 0;
    for (int i = 0; i < 10; ++i) {
        int x = 0;
        switch (s[i]) {
            case 'o':
                x = ORANGE;
                break;
            case 'g':
                x = GRAY;
                break;
            case 'r':
                x = RED;
                break;
        }
        bits |= x << (2 * i);
    }
    return bits;
}
constexpr int STATE_MASK = 0xFFFFF;
constexpr int CENTER_MASK = 0b111111;

vector<pair<int, int>> generate_rotations(int bits) {
    vector<pair<int, int>> result;
    for (int i = 0; i < 10; ++i) {
        int x = (bits >> 18) & 3;
        bits = (bits << 2) & STATE_MASK;
        bits |= x;
        bool ok=1;
        for (auto [r, _] : result) {
            if ((r & CENTER_MASK) == (bits & CENTER_MASK)) {
                ok=0;
                break;
            }
        }
        if (ok)
            result.push_back({bits, i});
    }

    return result;
}

vector<pair<State, int>> generate_moves(const State& state) {
    vector<pair<State, int>> result;
    for (auto [r, amount] : generate_rotations(state.o)) {
        State s = state;
        s.o = r;
        result.push_back({s, 1 + amount});
    }
    for (auto [r, amount] : generate_rotations(state.g)) {
        State s = state;
        s.g = r;
        result.push_back({s, 10 + amount});
    }
    for (auto [r, amount] : generate_rotations(state.r)) {
        State s = state;
        s.r = r;
        result.push_back({s, 19 + amount});
    }
    State s = state;
    {
        int o = s.o & CENTER_MASK;
        int g = s.g & CENTER_MASK;
        int r = s.r & CENTER_MASK;
        s.o = (s.o & ~CENTER_MASK) | g;
        s.g = (s.g & ~CENTER_MASK) | r;
        s.r = (s.r & ~CENTER_MASK) | o;
        result.push_back({s, 28});
    }
    {
        int o = s.o & CENTER_MASK;
        int g = s.g & CENTER_MASK;
        int r = s.r & CENTER_MASK;
        s.o = (s.o & ~CENTER_MASK) | g;
        s.g = (s.g & ~CENTER_MASK) | r;
        s.r = (s.r & ~CENTER_MASK) | o;
        result.push_back({s, 29});
    }
    return result;
}

array<string, 3> to_str(const State& state) {
    string o(10,'?'), g(10,'?'), r(10,'?');
    string toc = "ogr";
    for (int i = 0; i < 10; ++i) {
        o[i] = toc[(state.o >> (2*i)) & 3];
        g[i] = toc[(state.g >> (2*i)) & 3];
        r[i] = toc[(state.r >> (2*i)) & 3];
    }
    return {o, g, r};
}

string move_to_str(int mv) {
    string s;
    if (mv <= 9) {
        s = "o";
        s.push_back(mv + '0');
        return s;
    }
    if (mv <= 18) {
        s = "g";
        s.push_back(mv - 9 + '0');
        return s;
    }
    if (mv <= 27) {
        s = "r";
        s.push_back(mv - 18 + '0');
        return s;
    }
    s = "c";
    s.push_back(mv - 27 + '0');
    return s;
}

int main() {
    State start = {0,0,0};

    string s;
    cin >> s;
    start.o = str_to_bits(s);
    cin >> s;
    start.g = str_to_bits(s);
    cin >> s;
    start.r = str_to_bits(s);

    unordered_map<ll, ll> dist;
    dist[start.key()] = 0;

    unordered_map<ll, pair<State, int>> cf;

    queue<State> q;
    q.push(start);

    while (q.size()) {
        auto u = q.front();
        q.pop();

        if (is_solved(u)) {
            break;
        }

        for (auto [v, mv] : generate_moves(u)) {
            if (dist.count(v.key())) continue;
            dist[v.key()] = dist[u.key()] + 1;
            cf[v.key()] = {u, mv};
            q.push(v);
        }
    }
    State ptr = {
        .o = str_to_bits("oooooooooo"),
        .g = str_to_bits("gggggggggg"),
        .r = str_to_bits("rrrrrrrrrr")
    };

    vector<string> ans;

    while (cf.count(ptr.key())) {
        auto [nxt, mv] = cf[ptr.key()];

        ans.push_back(move_to_str(mv));

        ptr = nxt;
    }
    reverse(begin(ans), end(ans));
    cout << ans.size() << endl;
    for (auto s:  ans)cout << s << endl;
}
