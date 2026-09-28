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

vector<string> ans;
void apply_move(const string& s, State& state, bool append_ans = true) {
    if (append_ans)ans.push_back(s);

    int amount = s[1] - '0';
    if (s[0] == 'o') {
        int rem = (state.o >> (2*(10 - amount)));
        state.o = (state.o << (2 * amount)) & STATE_MASK;
        state.o |= rem;
        return;
    }
    if (s[0] == 'g') {
        int rem = (state.g >> (2*(10 - amount)));
        state.g = (state.g << (2 * amount)) & STATE_MASK;
        state.g |= rem;
        return;
    }
    if (s[0] == 'r') {
        int rem = (state.r >> (2*(10 - amount)));
        state.r = (state.r << (2 * amount)) & STATE_MASK;
        state.r |= rem;
        return;
    }
    {
        int o = state.o & CENTER_MASK;
        int g = state.g & CENTER_MASK;
        int r = state.r & CENTER_MASK;
        state.o = (state.o & ~CENTER_MASK) | g;
        state.g = (state.g & ~CENTER_MASK) | r;
        state.r = (state.r & ~CENTER_MASK) | o;
    }
    if (amount == 2) {
        int o = state.o & CENTER_MASK;
        int g = state.g & CENTER_MASK;
        int r = state.r & CENTER_MASK;
        state.o = (state.o & ~CENTER_MASK) | g;
        state.g = (state.g & ~CENTER_MASK) | r;
        state.r = (state.r & ~CENTER_MASK) | o;
    }
}

bool wheel_has(int wheel, int color) {
    for (int i = 0; i < 10; ++i) {
        if (((wheel >> (2 * i)) & 3) == color) return true;
    }
    return false;
}

void ensure_position(State& state, char prefix, int pos, int color, bool should_be_equal) {
    int curr_pos = -1;

    int wheel = prefix == 'o' ? state.o : (prefix == 'g' ? state.g : state.r);

    for (int i = 0; i < 10; ++i) {
        if (should_be_equal) {
            if (((wheel >> (2 * i)) & 3) == color) {
                curr_pos = i;
            }
        } else {
            if (((wheel >> (2 * i)) & 3) != color) {
                curr_pos = i;
            }
        }
    }

    assert(curr_pos != -1);
    if (curr_pos == pos) return;
    string mv = "gg";
    mv[0] = prefix;
    mv[1] = '0' + (pos - curr_pos + 10)%10;
    apply_move(mv, state);
}

int main() {
    State state = {0,0,0};

    string s;
    cin >> s;
    state.o = str_to_bits(s);
    cin >> s;
    state.g = str_to_bits(s);
    cin >> s;
    state.r = str_to_bits(s);


    int o_good = 0;
    int g_good = 0b01010101010101010101;
    int r_good = 0b10101010101010101010;

    int its = 0;
    while (!is_solved(state)) {
        // if (++its > 10) break;
        auto [o, g, r] = to_str(state);
        // cout << o << endl << g << endl << r << endl << endl;
        if (state.o != o_good) {
            if (wheel_has(state.g, ORANGE)) {
                ensure_position(state, 'o', 2, ORANGE, false);
                ensure_position(state, 'g', 0, ORANGE, true);
                apply_move("o1", state);
                apply_move("c1", state);
                apply_move("o9", state);
                apply_move("c2", state);
            } else {
                ensure_position(state, 'o', 0, ORANGE, false);
                ensure_position(state, 'r', 2, ORANGE, true);
                apply_move("r1", state);
                apply_move("c1", state);
                apply_move("r9", state);
                apply_move("c2", state);
            }
        } else if (state.g != g_good) {
            ensure_position(state, 'g', 2, GRAY, false);
            ensure_position(state, 'r', 0, GRAY, true);
            apply_move("g1", state);
            apply_move("c1", state);
            apply_move("g9", state);
            apply_move("c2", state);
        }
    }

    cout << ans.size() << endl;
    for (auto s : ans)cout << s << endl;
}
