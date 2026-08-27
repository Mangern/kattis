#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll M = 1e9+7;

struct node {
    ll num = -1;
    ll ss = -1;
    ll ssz = -1;
    ll smin = -1;
    ll smax = 1;
    node *left, *right;
    node *parent;

    node() {}
    node (int x) {
        num = x;
    }

    ll subtree_sum() {
        if (ss != -1)return ss;
        if (num != -1)return num;
        ss = left->subtree_sum() + right->subtree_sum();
        return ss;
    }

    ll subtree_size() {
        if (ssz != -1)return ssz;
        ssz = 1;
        if (num == -1) {
            ssz += left->subtree_size() + right->subtree_size();
        }
        return ssz;
    }

    ll subtree_min() {
        if (smin != -1)return smin;
        if (num != -1) {
            smin = num;
            return num;
        }
        smin = min(left->subtree_min(), right->subtree_min());
        return smin;
    }

    ll subtree_max() {
        if (smax != -1)return smax;
        if (num != -1) {
            smax = num;
            return num;
        }
        smax = max(left->subtree_max(), right->subtree_max());
        return smax;
    }
};

class Tree {

    node *root;

    node *parse_rec(const string& s, const vector<int>& paren_match, int l, int r) {
        if (s[l] != '(') {
            if (s[r] == ')') {
                cout << "WTF" << endl;
                exit(0);
            }
            node* leaf = new node{stoi(s.substr(l, r - l + 1))};
            return leaf;
        }

        node *curr = new node{};

        if (s[l+1] == '(') {
            curr->left = parse_rec(s, paren_match, l+1, paren_match[l+1]);
        } else {
            for (int i = l+1; i < r; ++i) {
                if (s[i] == ',') {
                    curr->left = parse_rec(s, paren_match, l+1, i-1);
                    break;
                }
            }
        }

        if (s[r-1] == ')') {
            curr->right = parse_rec(s, paren_match, paren_match[r-1], r-1);
        } else {
            for (int i = r -1; i > l; --i) {
                if (s[i] == ',') {
                    curr->right = parse_rec(s, paren_match, i+1, r-1);
                    break;
                }
            }
        }
        curr->left->parent = curr;
        curr->right->parent = curr;
        return curr;
    }

    void make_labels_rec(node* n, map<int,int>& labels, int& time) {
        if (n->num != -1) {
            labels[n->num] = time;
            n->num = time++;
            return;
        }
        make_labels_rec(n->left, labels, time);
        make_labels_rec(n->right, labels, time);
    }

    void relabel_rec(node* n, map<int,int>& labels) {
        if (n->num != -1) {
            n->num = labels[n->num];
            return;
        }
        relabel_rec(n->left, labels);
        relabel_rec(n->right, labels);
    }

    void compute_hashes(node* n, map<ll, vector<node*>>& hashes) {
        if (n->num == -1) {
            compute_hashes(n->left, hashes);
            compute_hashes(n->right, hashes);
        }
        ll s = n->subtree_sum();
        hashes[(s * s) % M].push_back(n);
    }

public:
    Tree(int n, string s) {
        vector<int> paren_match(s.length());

        stack<int> paren;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                paren.push(i);
            } else if (s[i] == ')') {
                int lft = paren.top();
                paren.pop();
                paren_match[lft] = i;
                paren_match[i] = lft;
            }
        }
        root = parse_rec(s, paren_match, 0, s.length() - 1);
    }

    map<int,int> make_labels() {
        map<int,int> labels;
        int time = 0;
        make_labels_rec(root, labels, time);
        return labels;
    }

    void relabel(map<int,int>& labels) {
        relabel_rec(root, labels);
    }

    map<ll, vector<node*>> get_hashes() {
        map<ll, vector<node*>> hashes;
        compute_hashes(root, hashes);
        return hashes;
    }
};

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    Tree tree_a(n, a), tree_b(n, b);

    map<int,int> labels = tree_a.make_labels();
    tree_b.relabel(labels);
    int ans = 0;

    map<ll, vector<node*>> hash_a = tree_a.get_hashes();
    map<ll, vector<node*>> hash_b = tree_b.get_hashes();

    for (auto [k, vna] : hash_a) {
        if (hash_b.count(k)) {
            vector<node*> vnb = hash_b[k];

            for (auto na : vna) for (auto nb : vnb) {

                if (na->subtree_size() == nb->subtree_size() &&
                    na->subtree_min() == nb->subtree_min() &&
                    na->subtree_max() == nb->subtree_max())++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
