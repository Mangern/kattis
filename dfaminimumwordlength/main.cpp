#include <bits/stdc++.h>
using namespace std;

struct DFA {
    string alphabet;
    int num_states;
    int initial;
    vector<bool> final;
    vector<map<char,int>> trans;

    DFA(const string& alphabet) {
        this->alphabet = alphabet;
        num_states     = 0;
    }

    void ensure_enough(int u) {
        if (u < num_states) return;
        final.resize(u+1);
        trans.resize(u+1);
        num_states = final.size();
    }

    void add_transition(int u, int v, char c) {
        ensure_enough(u);
        ensure_enough(v);
        trans[u][c] = v;
    }

    void mark_final(int u) {
        ensure_enough(u);
        final[u] = 1;
    }

    void set_initial(int u) {
        ensure_enough(u);
        initial = u;
    }

    bool accepts(const string &s) {
        int u = initial;

        for (char c : s) {
            if (!trans[u].count(c)) return false;
            u = trans[u][c];
        }
        return final[u];
    }

    int num_final() {
        int ret=0;
        for (auto x : final)ret+=x;
        return ret;
    }
};

string string_union(const string &str1, const string &str2) {
    string newstr = str1 + str2;
    sort(begin(newstr), end(newstr));
    newstr.erase(unique(begin(newstr), end(newstr)), end(newstr));
    return newstr;
}

DFA dfa_merge(const DFA& dfa1, const DFA& dfa2, function<bool(bool,bool)> final_op) {
    string new_alpha = string_union(dfa1.alphabet, dfa2.alphabet);
    DFA new_dfa(new_alpha);

    vector<pair<int, int>> subsets;
    subsets.push_back({dfa1.initial, dfa2.initial});
    new_dfa.set_initial(0);
    map<pair<int,int>, int> idx;
    idx[subsets[0]] = 0;
    for (int i = 0; i < subsets.size(); ++i) {
        auto [i1, j1] = subsets[i];
        for (char c : new_alpha) {
            int i2 = dfa1.trans[i1].at(c);
            int j2 = dfa2.trans[j1].at(c);

            pair<int,int> np = {i2, j2};

            if (idx.count(np)) {
                new_dfa.add_transition(i, idx[np], c);
                continue;
            }
            idx[np] = subsets.size();
            subsets.push_back(np);
            new_dfa.add_transition(i, idx[np], c);
        }
    }

    for (int i = 0; i < subsets.size(); ++i) {
        auto [i1, j1] = subsets[i];
        if (final_op(dfa1.final[i1], dfa2.final[j1])) new_dfa.mark_final(i);
    }
    return new_dfa;
}

DFA dfa_union(const DFA& dfa1, const DFA& dfa2) {
    return dfa_merge(dfa1, dfa2, [](bool a, bool b) { return a || b; });
}

DFA dfa_difference(const DFA& dfa1, const DFA& dfa2) {
    return dfa_merge(dfa1, dfa2, [](bool a, bool b) { return a && !b; });
}

DFA dfa_symmetric_difference(const DFA& dfa1, const DFA& dfa2) {
    return dfa_merge(dfa1, dfa2, [](bool a, bool b) { return (a && !b) || (!a && b); });
}

DFA dfa_read() {
    int n, c, s, f;

    cin >> n >> c >> s >> f;
    string str;

    cin >> str;

    DFA dfa(str);

    dfa.set_initial(s-1);

    for (int i = 0; i < f; ++i) {
        int u;
        cin >> u, --u;
        dfa.mark_final(u);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            int v;
            cin >> v, --v;
            dfa.add_transition(i, v, str[j]);
        }
    }
    return dfa;
}

int main() {
    DFA dfa = dfa_read();

    vector<int> dist(dfa.num_states, -1);
    queue<int> q;
    dist[dfa.initial] = 0;
    q.push(dfa.initial);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto [k, v] : dfa.trans[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int ans = 1000000000;
    for (int i = 0; i < dfa.num_states; ++i) {
        if (dfa.final[i] && dist[i] != -1) {
            ans = min(ans, dist[i]);
        }
    }

    cout << ans << endl;
}
