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
};

int main() {
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

    {
        int q;
        cin >> q;
        string s;
        getline(cin, s);
        while (q-->0) {
            getline(cin, s);
            cout << (dfa.accepts(s) ? "accept" : "reject") << endl;
        }
    }
}
