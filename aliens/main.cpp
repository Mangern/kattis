#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct state {
    int len, link;
    bool terminal = 0;
    map<char,int> next;
};

class SuffixAutomaton {
private:
    int sz, last;
    vector<state> states;

    vector<int> longest_path; // longest path from root to node i
    vector<int> parent; // parent in longest path from root
    vector<int> num_occurences; // number of occurances of substring denoted by node i
    vector<vector<int>> radj; // reverse graph of automaton

    vector<int> dist_to_terminal;

    void init(int n) {
        states = vector<state>(2 * n);

        sz = 1;
        last = 0;
        states[0].link = -1;
        states[0].len = 0;

        longest_path = vector<int>(2 * n, -1);
        parent = vector<int>(2 * n, -1);
        num_occurences = vector<int>(2 * n, -1);
        radj = vector<vector<int>>(2 * n, vector<int>());
        dist_to_terminal = vector<int>(2 * n, -1);
    }

    void extend(char c) {
        int cur = sz++;
        states[cur].len = states[last].len + 1;
        int p = last;

        while (p != -1 && !states[p].next.count(c)) {
            states[p].next[c] = cur;
            p = states[p].link;
        }

        if (p == -1) {
            states[cur].link = 0;
        } else {
            int q = states[p].next[c];

            if (states[p].len + 1 == states[q].len) {
                states[cur].link = q;
            } else {
                int clone = sz++;
                states[clone].len = states[p].len + 1;
                states[clone].link = states[q].link;
                states[clone].next = states[q].next;

                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone;
                    p = states[p].link;
                }

                states[q].link = clone;
                states[cur].link = clone;
            }
        }

        last = cur;
    }

    void register_terminals() {
        int cur = last;

        while (cur != -1) {
            states[cur].terminal = 1;
            cur = states[cur].link;
        }
    }

    void find_occurences(int u = 0) {
        if (num_occurences[u] != -1)return;

        num_occurences[u] = 0;
        if (states[u].terminal)++num_occurences[u];

        for (auto [c, v] : states[u].next) {
            find_occurences(v);
            num_occurences[u] += num_occurences[v];
        }
    }

    void construct_radj() {
        for (int i = 0; i < sz; ++i) {
            for (auto [k, j] : states[i].next) {
                radj[j].push_back(i);
            }
        }
    }

    void compute_longest_path(int u) {
        if (longest_path[u] != -1)return;
        longest_path[u] = 0;

        for (int v : radj[u]) {
            compute_longest_path(v);
            if (longest_path[v] + 1 > longest_path[u]) {
                longest_path[u] = longest_path[v] + 1;
                parent[u] = v;
            }
        }
    }
    int shortest_path_to_terminal(int u) {
        if (dist_to_terminal[u] != -1)return dist_to_terminal[u];

        if (states[u].terminal)return 0;

        dist_to_terminal[u] = sz+1;

        for (auto [k, v] : states[u].next) {
            dist_to_terminal[u] = min(
                dist_to_terminal[u], 
                shortest_path_to_terminal(v) + 1
            );
        }

        return dist_to_terminal[u];
    }

public:
    SuffixAutomaton(string s) {
        init(s.length());
        for (char c : s)extend(c);

        register_terminals();

        construct_radj();

        find_occurences();

        // increasing id is also topo ordering
        for (int i = 0; i < sz; ++i)compute_longest_path(i);

    }

    pair<int,int> find_longest_repeating(int m) {
        int longest_node = -1;

        // skip the root because the root represents
        // empty substring (meaningless)
        for (int i = 1; i < sz; ++i) {
            if (num_occurences[i] >= m) {
                if (longest_node == -1 || longest_path[longest_node] < longest_path[i]) {
                    longest_node = i;
                } else if (longest_path[longest_node] == longest_path[i]) {
                    if (shortest_path_to_terminal(i) < shortest_path_to_terminal(longest_node)) {
                        longest_node = i;
                    }
                }
            }
        }

        if (longest_node == -1)return {-1, -1};

        int len = longest_path[longest_node];

        int sp = shortest_path_to_terminal(longest_node);

        int pos = states.size() / 2 - sp - len;

        return {len, pos};
    }
};

int main() {
    while (true) {
        int m;
        string s;
        cin >> m;

        if (!m)break;
        cin >> s;

        SuffixAutomaton sa(s);

        auto [len, pos] = sa.find_longest_repeating(m);

        if (len == -1) {
            cout << "none" << endl;
        } else {
            cout << len << " " << pos << endl;
        }
    }
}
