#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct state {
    char nums[16];

    bool iswin() const {
        if (
            nums[0] != (char)0 || 
            nums[4] != (char)1 || 
            nums[8] != (char)2 || 
            nums[12]!= (char)3)return false;

        for (int i = 0; i < 16; i += 4) {
            for (int j = i; j < i+4; ++j) if (nums[j] != nums[i])return false;
        }
        return true;
    }

    long long id() const {
        long long res = 0;
        for (int i = 15; i >= 0; --i) {
            res *= 4;
            res += nums[i];
        }
        return res;
    }
};

void cyclic_row(char* nums, int pos, bool rev = 0) {
    for (int i = 0; i < (rev ? 3 : 1); ++i) {
        char tmp = nums[4 * pos];
        nums[4*pos] = nums[4*pos+3];
        nums[4*pos+3] = nums[4*pos+2];
        nums[4*pos+2] = nums[4*pos+1];
        nums[4*pos+1] = tmp;
    }
}

void cyclic_col(char* nums, int pos, bool rev = 0) {
    for (int i = 0; i < (rev ? 3 : 1); ++i) {
        char tmp = nums[pos];
        nums[pos] = nums[pos + 3 * 4];
        nums[pos+3 * 4] = nums[pos+2 * 4];
        nums[pos+2 * 4] = nums[pos+1 * 4];
        nums[pos+1 * 4] = tmp;
    }
}

vector<state> next_states(state s) {
    state a;
    vector<state> res;
    a = s;
    cyclic_row(a.nums, 0);
    res.push_back(a);
    a = s;
    cyclic_row(a.nums, 1);
    res.push_back(a);
    a = s;
    cyclic_row(a.nums, 2);
    res.push_back(a);
    a = s;
    cyclic_row(a.nums, 3);
    res.push_back(a);

    a = s;
    cyclic_row(a.nums, 0, 1);
    res.push_back(a);
    a = s;
    cyclic_row(a.nums, 1, 1);
    res.push_back(a);
    a = s;
    cyclic_row(a.nums, 2, 1);
    res.push_back(a);
    a = s;
    cyclic_row(a.nums, 3, 1);
    res.push_back(a);

    a = s;
    cyclic_col(a.nums, 0);
    res.push_back(a);
    a = s;
    cyclic_col(a.nums, 1);
    res.push_back(a);
    a = s;
    cyclic_col(a.nums, 2);
    res.push_back(a);
    a = s;
    cyclic_col(a.nums, 3);
    res.push_back(a);

    a = s;
    cyclic_col(a.nums, 0, 1);
    res.push_back(a);
    a = s;
    cyclic_col(a.nums, 1, 1);
    res.push_back(a);
    a = s;
    cyclic_col(a.nums, 2, 1);
    res.push_back(a);
    a = s;
    cyclic_col(a.nums, 3, 1);
    res.push_back(a);

    return res;
}

int main() {
    state start;

    const map<char,char> remap ={
        {'R', 0},
        {'G', 1},
        {'B', 2},
        {'Y', 3}
    };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c;
            cin >> c;
            start.nums[i*4+j] = remap.at(c);
        }
    }

    state rev_start;

    for (int i = 0; i < 16; ++i)rev_start.nums[i] = (char)(i/4);

    map<ll,int> rev_dist;

    queue<pair<state,int>> q;

    q.push({rev_start, 0});
    rev_dist[rev_start.id()] = 0;

    while (q.size()) {
        auto [s, d] = q.front();
        q.pop();

        if (d <= 5) {
            for (auto st : next_states(s)) {
                if (!rev_dist.count(st.id())) {
                    rev_dist[st.id()] = d+1;
                    q.push({st, d+1});
                }
            }
        }
    }

    unordered_set<ll> vis;
    vis.insert(start.id());

    q.push({start, 0});

    while (q.size()) {
        auto [s, d] = q.front();
        q.pop();

        if (rev_dist.count(s.id())) {
            cout << d + rev_dist[s.id()] << endl;
            return 0;
        }

        if (d == 13) {
            cout << 13 << endl;
            return 0;
        }

        for (auto st : next_states(s)) {
            if (!vis.count(st.id())) {
                q.push({st, d+1});
                vis.insert(st.id());
            }
        }
    }
}
