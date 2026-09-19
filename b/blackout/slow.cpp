#include <bits/stdc++.h>
#include <random>
using namespace std;
using ii = pair<int, int>;

vector<int> move_idxs;
vector<int> move_masks;
vector<int> move_ver_refl;
vector<int> move_hor_refl;
vector<ii> moves;

int LMASK, RMASK;
int TOPMASK, BOTMASK;

int move_to_mask(int r1, int c1, int r2, int c2) {
    if (r1 == r2) {
        int mask = 0;
        for (int j = c1; j <= c2; ++j) {
            int idx = r1 * 6 + j;
            mask |= 1<<idx;
        }
        return mask;
    } else if (c1 == c2) {
        int mask = 0;
        for (int i = r1; i <= r2; ++i) {
            int idx = i * 6 + c1;
            mask |= 1<<idx;
        }
        return mask;
    }

    return 0;
}

void pre() {
    for (int r1 = 0; r1 < 5; ++r1) {
        for (int c1 = 0; c1 < 6; ++c1) {
            if (c1 < 3) {
                LMASK |= 1<<(r1 * 6 + c1);
            } else {
                RMASK |= 1<<(r1 * 6 + c1);
            }
            if (r1 < 2) {
                TOPMASK |= 1<<(r1 * 6 + c1);
            } else if (r1 > 2) {
                BOTMASK |= 1<<(r1 * 6 + c1);
            }
            for (int r2 = r1; r2 < 5; ++r2) {
                for (int c2 = c1; c2 < 6; ++c2) {
                    int mask = move_to_mask(r1, c1, r2, c2);
                    if (mask) {
                        move_masks.push_back(mask);
                        moves.push_back({r1 * 6 + c1, r2 * 6 + c2});
                    }
                }
            }
        }
    }

    move_idxs.resize(moves.size());
    iota(begin(move_idxs), end(move_idxs), 0);
    sort(begin(move_idxs), end(move_idxs), [&](auto i, auto j) {
        return __builtin_popcount(move_masks[i]) > __builtin_popcount(move_masks[j]);
    });

    move_ver_refl.resize(moves.size());
    move_hor_refl.resize(moves.size());

    for (int i : move_idxs) {
        int r1, c1, r2, c2;
        auto [idx1, idx2] = moves[i];
        r1 = idx1 / 6, c1 = idx1 % 6, r2 = idx2 / 6, c2 = idx2 % 6;

        {
            int nc1 = 5 - c1;
            int nc2 = 5 - c2;
            if (nc2 < nc1)swap(nc1, nc2);
            int mask = move_to_mask(r1, nc1, r2, nc2);
            for (int j : move_idxs) {
                if (move_masks[j] == mask) {
                    move_ver_refl[i] = j;
                    break;
                }
            }
        }
        {
            int nr1 = 4 - r1;
            int nr2 = 4 - r2;
            if (nr2 < nr1)swap(nr1, nr2);
            int mask = move_to_mask(nr1, c1, nr2, c2);
            for (int j : move_idxs) {
                if (move_masks[j] == mask) {
                    move_hor_refl[i] = j;
                    break;
                }
            }
        }
    }
}

pair<bool, int> normalize_ver(int state) {
    int lcnt = __builtin_popcount(state & LMASK);
    int rcnt = __builtin_popcount(state & RMASK);
    if (lcnt >= rcnt) {
        return {false, state};
    }

    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 3; ++c) {
            int lidx = r * 6 + c;
            int ridx = r * 6 + 5 - c;
            int lbit = (state >> lidx) & 1;
            int rbit = (state >> ridx) & 1;
            state ^= lbit << lidx;
            state ^= rbit << ridx;
            state |= lbit << ridx;
            state |= rbit << lidx;
        }
    }
    return {true, state};
}

pair<bool, int> normalize_hor(int state) {
    int tcnt = __builtin_popcount(state & TOPMASK);
    int bcnt = __builtin_popcount(state & BOTMASK);
    if (tcnt >= bcnt) {
        return {false, state};
    }
    // 0 1 2 3 4

    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 6; ++c) {
            int tidx = r * 6 + c;
            int ridx = (4 - r) * 6 + c;
            int tbit = (state >> tidx) & 1;
            int bbit = (state >> ridx) & 1;
            state ^= tbit << tidx;
            state ^= bbit << ridx;
            state |= tbit << ridx;
            state |= bbit << tidx;
        }
    }
    return {true, state};
}

int reflect_move_ver(int mvi) {
    if (mvi < 0) return mvi;
    return move_ver_refl[mvi];
}

int reflect_move_hor(int mvi) {
    if (mvi < 0) return mvi;
    return move_hor_refl[mvi];
}

unordered_map<int, int> dp;

int find_winning_move(int state); 

int find_winning_move_impl(int state) {
    int cnt = __builtin_popcount(state);
    if (dp.count(state)) return dp[state];
    int &r = dp[state];
    if (cnt == 30) {
        return r = -1;
    }

    for (int i : move_idxs) {
        int mv = move_masks[i];
        int nstate = state | mv;
        if (__builtin_popcount(nstate) > cnt) {
            int opponent_winning = find_winning_move(nstate);
            if (opponent_winning == -1) {
                return r = i;
            }
        }
    }
    // No winning moves for us :(
    return r = -1;
}

int find_winning_move(int state) {
    auto [refl_ver, nstate] = normalize_ver(state);
    auto [refl_hor, nnstate] = normalize_hor(nstate);

    int mvi = find_winning_move_impl(nnstate);
    if (refl_hor) 
        mvi = reflect_move_hor(mvi);
    if (refl_ver)
        mvi = reflect_move_ver(mvi);
    return mvi;
}

mt19937 gen(random_device{}());

int find_random_move(int state) {
    int cnt = __builtin_popcount(state);
    if (cnt == 30) {
        return -1;
    }
    uniform_int_distribution<int> dist(0, moves.size() - 1);

    for (;;) {
        int i = dist(gen);
        int mv = move_masks[i];
        if (__builtin_popcount(mv) < 4) continue;
        int nstate = state | mv;
        if (__builtin_popcount(nstate) > cnt) {
            return i;
        }
    }
    // No winning moves for us :(
    return -1;
}

void print_state(int state) {
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 6; ++c) {
            int idx = r * 6 + c;
            int val = (state >> idx) & 1;
            cout << val;
        }
        cout << endl;
    }
}

const unordered_map<int, int> round1_moves = {
    {1006633023, 26},
    {100663359, 104},
    {1023, 26},
    {1040187455, 49},
    {1048639, 56},
    {1056964671, 89},
    {1065023, 112},
    {1065279, 147},
    {1087, 32},
    {114751, 126},
    {117440575, 39},
    {122943, 127},
    {12351, 16},
    {12582975, 151},
    {127, 95},
    {127039, 58},
    {131135, 37},
    {133183, 160},
    {134217791, 96},
    {136314943, 24},
    {136347711, 38},
    {136348223, 26},
    {14680127, 95},
    {15728703, 65},
    {1572927, 152},
    {1599, 32},
    {16252991, 88},
    {16447, 152},
    {16515135, 89},
    {16703, 138},
    {16777279, 127},
    {17039423, 42},
    {17043519, 38},
    {17043583, 26},
    {1835071, 95},
    {1855, 44},
    {191, 25},
    {196671, 37},
    {1983, 147},
    {201326655, 91},
    {2047, 154},
    {2097215, 64},
    {2111, 95},
    {2129983, 112},
    {2130495, 147},
    {229439, 127},
    {234881087, 9},
    {245823, 120},
    {24639, 56},
    {251658303, 26},
    {254015, 49},
    {255, 43},
    {258111, 50},
    {262207, 129},
    {266303, 64},
    {266367, 147},
    {268435519, 109},
    {272629823, 49},
    {272695359, 88},
    {272696383, 26},
    {28735, 127},
    {3135, 8},
    {3145791, 111},
    {319, 128},
    {32831, 157},
    {33343, 134},
    {33554495, 104},
    {34086975, 96},
    {34087103, 26},
    {3647, 26},
    {3670079, 101},
    {3903, 26},
    {3932223, 38},
    {402653247, 109},
    {4031, 88},
    {4095, 89},
    {4159, 16},
    {4194367, 163},
    {4223, 151},
    {4259903, 108},
    {4260927, 121},
    {447, 25},
    {469762111, 44},
    {49215, 156},
    {503316543, 48},
    {50331711, 38},
    {511, 88},
    {520093759, 58},
    {524351, 145},
    {532543, 112},
    {532671, 128},
    {536870975, 127},
    {545259583, 7},
    {545390655, 38},
    {545392703, 26},
    {57407, 132},
    {575, 128},
    {575, 128},
    {61503, 120},
    {6291519, 157},
    {65599, 7},
    {66623, 148},
    {67108927, 96},
    {68157503, 31},
    {68173887, 38},
    {68174143, 18},
    {7340095, 94},
    {7864383, 95},
    {786495, 111},
    {805306431, 17},
    {8126527, 154},
    {8255, 42},
    {831, 43},
    {8383, 154},
    {8388671, 141},
    {8519743, 152},
    {8521791, 158},
    {939524159, 26},
    {959, 9},
    {98367, 64},
};


void search() {
    int state = 0;
    state |= move_masks[5];

    // for (int i = 0; i < moves.size(); ++i) {
    //     int nstate = state | move_masks[i];
    //     if (__builtin_popcount(nstate) > __builtin_popcount(state)) {
    //         int best_move = find_winning_move(nstate);
    //
    //         cout << "{" << nstate << ", " << best_move << "}," << endl;
    //     }
    // }

    unordered_map<int, int> round2_states;
    for (auto [round1_state, round1_mvi] : round1_moves) {
        int state = round1_state | move_masks[round1_mvi];

        for (int i : move_idxs) {
            int nstate = state | move_masks[i];
            if (__builtin_popcount(nstate) > __builtin_popcount(state)) {
                int best_move = find_winning_move(nstate);
                round2_states[nstate] = best_move;
            }
        }
    }

    for (auto [r2_state, r2_mvi] : round2_states) {
        cout << "{" << r2_state << ", " << r2_mvi << "}," << endl;
    }
}

int main() {
    pre();

    search();
    return 0;

    int T;
    cin >> T;

    while (T-->0) {
        int round = 0;

        int state = 0;
        for (;; round++) {
            int mvi;
            if (round == 0) {
                mvi = 5;
            } else if (round == 1) {
                assert(round1_moves.count(state));
                mvi = round1_moves.at(state);
            } else {
                mvi = find_winning_move(state);
            }

            state |= move_masks[mvi];

            auto [idx1, idx2] = moves[mvi];
            int r1, c1, r2, c2;
            r1 = idx1 / 6 + 1, c1 = idx1 % 6 + 1, r2 = idx2 / 6 + 1, c2 = idx2 % 6 + 1;

            cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;

            // cerr << "Move index: " << mvi << endl;
            // print_state(state);

            string cmd;
            cin >> cmd;

            if (cmd == "GAME") break;

            cin >> r1 >> c1 >> r2 >> c2;
            --r1, --c1, --r2, --c2;

            int mask = move_to_mask(r1, c1, r2, c2);
            state |= mask;
        }
    }
    //
    // cout << dp.size() << endl;
}
