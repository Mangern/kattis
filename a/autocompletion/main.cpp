#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        bool term;
        Node* parent;
        Node* next[26];
        int euler_begin;
        int euler_end;

        Node() {
            term = false;
            parent = 0;
            memset(next, 0, sizeof next);
        }
    };
    struct Iterator {
        Node* node;
        Trie* trie;
        string outside_suffix;

        void tab(int count) {
            if (outside_suffix.length()) {
                return;
            }

            int l = upper_bound(trie->terminators.begin(), trie->terminators.end(), pair<int,Node*>{node->euler_begin, node}) 
                    - trie->terminators.begin();
            int r = lower_bound(trie->terminators.begin(), trie->terminators.end(), pair<int,Node*>{node->euler_end, node})
                    - trie->terminators.begin();

            if (l >= r) return;

            node = trie->terminators[l + (count - 1) % (r - l)].second;
        }

        void advance(char c) {
            if (outside_suffix.length() || !node->next[c-'a']) {
                outside_suffix.push_back(c);
                return;
            }
            node = node->next[c-'a'];
        }

        string to_string() {
            string result;
            Node* ptr = node;
            while (ptr) {
                Node* par = ptr->parent;
                if (!par) break;
                char c;
                for (c = 'a'; c <= 'z'; ++c) {
                    if (par->next[c-'a'] == ptr) {
                        result.push_back(c);
                        break;
                    }
                }
                ptr = par;
            }
            reverse(std::begin(result), std::end(result));
            result.append(outside_suffix);
            return result;
        }
    };

    Node* root;
    vector<pair<int, Node*>> terminators;

    Trie() {
        root = new Node{};
    }

    void insert(const string& s) {
        Node* n = root;
        for (char c : s) {
            if (!n->next[c-'a']) {
                n->next[c-'a'] = new Node{};
                n->next[c-'a']->parent = n;
            }
            n = n->next[c-'a'];
        }
        n->term = true;
    }

    void build_dfs(Node* node, int* T) {
        node->euler_begin = (*T)++;
        if (node->term) {
            terminators.emplace_back(node->euler_begin, node);
        }
        for (int i = 0; i < 26; ++i) {
            if (node->next[i]) {
                build_dfs(node->next[i], T);
            }
        }
        node->euler_end = (*T)++;
    }

    void build() {
        int T = 0;
        build_dfs(root, &T);
    }

    Iterator begin() {
        return Iterator{
            .node = root,
            .trie = this,
        };
    }
};

int main() {
    int n;
    cin >> n;

    Trie trie;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    trie.build();

    int q;
    cin >> q;
    while (q-->0) {
        string s;
        cin >> s;

        Trie::Iterator it = trie.begin();
        for (int i = 0; i < s.length(); ) {
            if (s[i] == '#') {
                int j;
                for (j = i; j < s.length() && s[j] == '#'; ++j);
                it.tab(j - i);
                i = j;
            } else {
                it.advance(s[i]);
                ++i;
            }
        }
        string res = it.to_string();
        cout << res << '\n';
    }
}
