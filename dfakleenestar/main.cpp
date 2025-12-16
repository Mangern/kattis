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

struct NFA {
    static constexpr char EPS = 0;

    string alphabet;
    int num_states;
    int initial;
    vector<bool> final;
    vector<map<char,vector<int>>> trans;

    NFA(const string& alphabet) {
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
        trans[u][c].push_back(v);
    }

    void mark_final(int u) {
        ensure_enough(u);
        final[u] = 1;
    }

    void set_initial(int u) {
        ensure_enough(u);
        initial = u;
    }

    int num_final() {
        int ret=0;
        for (auto x : final)ret+=x;
        return ret;
    }

    vector<int> eps_closure(vector<int> subset) const {
        set<int> have(subset.begin(), subset.end());
        for (int i = 0; i < subset.size(); ++i) {
            int u = subset[i];
            if (trans[u].count(EPS)) {
                for (int v : trans[u].at(EPS)) {
                    if (!have.count(v)) {
                        have.insert(v);
                        subset.push_back(v);
                    }
                }
            }
        }
        sort(begin(subset), end(subset));
        return subset;
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

pair<DFA, vector<vector<int>>> subset_construct(const NFA &nfa) {
    DFA new_dfa(nfa.alphabet);
    auto start = nfa.eps_closure({nfa.initial});
    vector<vector<int>> subsets;
    map<vector<int>, int> idx;
    idx[start] = 0;
    subsets.push_back(start);
    new_dfa.set_initial(0);

    for (int i = 0; i < subsets.size(); ++i) {
        for (char c : nfa.alphabet) {
            vector<int> news;
            for (int u : subsets[i]) if (nfa.trans[u].count(c)) {
                for (int v : nfa.trans[u].at(c)) {
                    news.push_back(v);
                }
            }
            news = nfa.eps_closure(news);
            news.erase(unique(begin(news), end(news)),end(news));

            if (!idx.count(news)) {
                idx[news] = subsets.size();
                subsets.push_back(news);
            }
            new_dfa.add_transition(i, idx[news], c);
        }
    }
    return {new_dfa, subsets};
}

DFA dfa_concat(const DFA& dfa1, const DFA& dfa2) {
    string new_alpha = string_union(dfa1.alphabet, dfa2.alphabet);
    // make NFA containing both dfas with epsilon transition from 1.final to 2.initial
    NFA nfa(new_alpha);
    nfa.set_initial(dfa1.initial);

    for (int i = 0; i < dfa1.num_states; ++i) {
        for (char c : dfa1.alphabet) {
            nfa.add_transition(i, dfa1.trans[i].at(c), c);
        }
    }

    for (int i = 0; i < dfa2.num_states; ++i) {
        for (char c : dfa2.alphabet) {
            nfa.add_transition(
                dfa1.num_states + i, 
                dfa1.num_states + dfa2.trans[i].at(c), 
                c
            );
        }
    }

    for (int i = 0; i < dfa1.num_states; ++i) {
        if (dfa1.final[i]) {
            nfa.add_transition(i, dfa1.num_states, NFA::EPS);
        }
    }

    auto [new_dfa, subsets] = subset_construct(nfa);

    for (int i = 0; i < subsets.size(); ++i) {
        bool isf=0;
        for (int v : subsets[i]) if (v >= dfa1.num_states) {
            int idx2 = v - dfa1.num_states;
            if (dfa2.final[idx2]) {
                new_dfa.mark_final(i);
            }
        }
    }
    return new_dfa;
}

DFA dfa_kleene(const DFA& dfa) {
    NFA nfa(dfa.alphabet);
    nfa.set_initial(0);
    nfa.add_transition(0, 1+dfa.initial, NFA::EPS);

    for (int i = 0; i < dfa.num_states; ++i) {
        for (char c : dfa.alphabet) {
            nfa.add_transition(1+i, 1+dfa.trans[i].at(c), c);
        }

        if (dfa.final[i]) {
            nfa.add_transition(1+i, 0, NFA::EPS);
        }
    }

    auto [new_dfa, subsets] = subset_construct(nfa);

    for (int i = 0; i < subsets.size(); ++i) {
        for (int v : subsets[i]) {
            if (v == 0 || dfa.final[v-1]) {
                new_dfa.mark_final(i);
            }
        }
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

DFA dfa_intersection(const DFA& dfa1, const DFA& dfa2) {
    return dfa_merge(dfa1, dfa2, [](bool a, bool b) { return a && b; });
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

    DFA ret = dfa_kleene(dfa);

    cout << ret.num_states << " " << ret.alphabet.size() << " " << ret.initial+1 << " " << ret.num_final() << endl;
    cout << ret.alphabet << endl;

    for (int i = 0; i < ret.num_states; ++i) {
        if (ret.final[i])cout << i+1 << " ";
    }
    cout << endl;

    for (int i = 0; i < ret.num_states; ++i) {
        for (int j = 0; j < ret.alphabet.size(); ++j) {
            cout << ret.trans[i][ret.alphabet[j]]+1 << " ";
        }
        cout << endl;
    }
}
