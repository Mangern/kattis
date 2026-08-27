#include <bits/stdc++.h>
using namespace std;

struct Dice {
    unsigned int a;
    unsigned int c;
    unsigned int x;
    int id;

    int roll() {
        x = a * x + c;
        ++id;
        return (x >> 16) % 6 + 1;
    }
};

int state[11];
int max_score;

int field_max[11] = {
    1 * 5,
    2 * 5,
    3 * 5,
    4 * 5,
    5 * 5,
    6 * 5,
    30,
    2 * 5 + 3 * 6,
    1 * 5 + 4 * 6,
    50,
    6 * 5
};

int maximize(int field, const vector<int>& rolls) {
    if (field <= 5) {
        int cnt = 0;
        for (auto x : rolls)if (x == field+1)++cnt;
        return min(cnt, 5) * (field + 1);
    }

    if (field == 6) {
        // sequence
        bool has[6] = {0};

        for (const auto& x : rolls)has[x-1] = 1;

        if (has[1] && has[2] && has[3] && has[4] && has[5])return 30;
        if (has[0] && has[1] && has[2] && has[3] && has[4])return 30;
        return 0;
    }

    if (field == 7) {
        // full house

        int cnt[6] = {0};
        for (const auto& x : rolls)++cnt[x-1];

        int mx3 = -1;
        int mx2 = -1;

        for (int i = 0; i < 6; ++i) {
            if (cnt[i] >= 3) {
                mx2 = mx3;
                mx3 = i;
            } else if (cnt[i] == 2) {
                mx2 = i;
            }
        }
        if (mx2 == -1 || mx3 == -1)return 0;
        return 3 * (mx3 + 1) + 2 * (mx2 + 1);
    }

    if (field == 8) {
        // four of a kind
        int cnt[6] = {0};

        for (const auto& x : rolls)++cnt[x-1];

        int mx4 = -1;
        int mx1 = -1;

        for (int i = 0; i < 6; ++i) {
            if (cnt[i] >= 4) {
                mx1 = mx4;
                mx4 = i;
            } else if (cnt[i] >= 1) {
                mx1 = i;
            }
        }

        if (mx1 == -1 || mx4 == -1)return 0;
        return 4 * (mx4 + 1) + mx1 + 1;
    }

    if (field == 9) {
        // five of a kind
        int cnt[6] = {0};

        for (const auto& x : rolls)++cnt[x-1];

        for (int i = 0; i < 6; ++i)if (cnt[i] == 5)return 50;
        return 0;
    }

    if (field == 10) {
        // chance
        vector<int> cpy(begin(rolls), end(rolls));
        sort(begin(cpy), end(cpy));

        int res = 0;
        for (int i = 0; i < 5; ++i) {
            res += cpy.back();
            cpy.pop_back();
        }
        return res;
    }
    return 0;
}

int maximize_forced(int field, const vector<int>& rolls, int forced_roll) {
    // maximize the outcome for the given field,
    // but we HAVE TO use forced_roll as one of our dice

    if (field <= 5) {
        int cnt = 0;
        for (auto x : rolls)if (x == field + 1)++cnt;
        return (field + 1) * (min(cnt, 4) + (forced_roll == field + 1));
    }

    if (field == 6) {
        // sequence
        bool has[6] = {0};
        for (const auto& x : rolls)has[x-1] = 1;

        has[forced_roll - 1] = 1;

        if (forced_roll == 1 || forced_roll == 6) {
            return (has[1] && has[2] && has[3] && has[4]) ? 30 : 0;
        }
        if (has[0] && has[1] && has[2] && has[3] && has[4])return 30;
        if (has[1] && has[2] && has[3] && has[4] && has[5])return 30;
        return 0;
    }

    if (field == 7) {
        // full house
        int cnt[6] = {0};
        for (const auto& x : rolls)++cnt[x-1];

        ++cnt[forced_roll-1];

        int situ32 = -1, situ23 = -1;

        for (int i = 0; i < 6; ++i) if (i != forced_roll - 1) {
            if (cnt[i] >= 2 && cnt[forced_roll - 1] >= 3) {
                situ32 = max(situ32, 3 * forced_roll + 2 * (i+1));
            }
            if (cnt[i] >= 3 && cnt[forced_roll - 1] >= 2) {
                situ23 = max(situ23, 3 * (i+1) + 2 * forced_roll);
            }
        }
        return max(situ23, situ32);
    }

    if (field == 8) {
        // four of a kind
        int cnt[6] = {0};
        for (const auto& x : rolls)++cnt[x-1];

        ++cnt[forced_roll - 1];

        int situ41 = -1, situ14 = -1;

        for (int i = 0; i < 6; ++i) if (i != forced_roll - 1) {
            if (cnt[i] >= 1 && cnt[forced_roll - 1] >= 4) {
                situ41 = max(situ41, 4 * forced_roll + 1 * (i + 1));
            }
            if (cnt[i] >= 4 && cnt[forced_roll - 1] >= 1) {
                situ14 = max(situ14, forced_roll + 4 * (i + 1));
            }
        }

        return max(situ14, situ41);
    }
    
    if (field == 9) {
        // five of a kind

        int cnt = 1;

        for (const auto& x : rolls) if (x == forced_roll)++cnt;

        return (cnt >= 5 ? 50 : 0);
    }

    if (field == 10) {
        // chance
        vector<int> top4(begin(rolls), end(rolls));
        sort(begin(top4), end(top4));
        int res = forced_roll;
        for (int i = 0; i < 4; ++i) {
            res += top4.back();
            top4.pop_back();
        }
        return res;
    }

    return 0;
}

map<pair<int, int>, int> save_best;

inline int state_val() {
    int res = 0;
    for (int i = 0; i < 11; ++i) {
        if (state[i] != -1)res |= (1<<i);
    }
    return res;
}

void search(Dice dice, int level = 0, int score = 0) {
    if (level == 11) {
        max_score = max(max_score, score);
        cout << max_score << endl;
        return;
    }

    int max_res_score = 0;

    for (int i = 0; i < 11; ++i) {
        if (state[i] == -1)max_res_score += field_max[i];
        else max_res_score += state[i];
    }

    if (max_res_score <= max_score)return;

    if (save_best.count({dice.id, state_val()}) > score)return;

    save_best[{dice.id, state_val()}] = score;

    vector<int> rolls;

    for (int i = 0; i < 5; ++i)rolls.push_back(dice.roll());

    for (int i = 0; i < 11; ++i) if (state[i] == -1) {
        state[i] = maximize(i, rolls);
        search(dice, level + 1, score + state[i]);
        state[i] = -1;
    }

    for (int r = 0; r < 10; ++r) {
        int next_roll = dice.roll();

        for (int i = 0; i < 11; ++i) if (state[i] == -1) {
            state[i] = maximize_forced(i, rolls, next_roll);
            search(dice, level + 1, score + state[i]);
            state[i] = -1;
        }
        rolls.push_back(next_roll);
    }
}

int main() {
    Dice dice;

    while (true) {
        cin >> dice.a >> dice.c >> dice.x;
        dice.id = 0;
        if (!dice.a && !dice.c && !dice.x)break;

        memset(state, -1, sizeof state);
        save_best.clear();
        max_score = 0;
        search(dice);
        cout << max_score << endl;
    }
}
