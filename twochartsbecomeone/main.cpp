//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;

struct node {
    int v;
    vector<node*> children;
};

node* parse(const string& s, const vector<int> &pmatch, int l, int r) {
    int i = l;
    while (!isdigit(s[i]))i++;
    int j = i;
    while (j < r && isdigit(s[j]))j++;

    node *n = new node;
    n->v = stoll(s.substr(i, j - i));

    i = j;
    while (i < r) {
        while (i < r && s[i] != '(')++i;
        if (i == r) break;
        int j = pmatch[i];
        assert(j != -1);
        n->children.push_back(parse(s, pmatch, i + 1, j));
        i = j + 1;
    }

    sort(n->children.begin(), n->children.end(), [](node* n1, node* n2) {
        return n1->v < n2->v;
    });

    return n;
}

vector<int> pmatch(const string &s) {
    vector<int> stk;
    vector<int> res(s.length(), -1);

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else if (s[i] == ')') {
            int j = stk.back();
            stk.pop_back();
            res[i] = j;
            res[j] = i;
        }
    }
    return res;
}

void dbg(node *node, int dep = 0) {
    for (int i = 0; i < dep; ++i)cout << ' ';
    cout << node->v << endl;

    for (auto ch : node->children) {
        dbg(ch, dep + 2);
    }
}

bool eq(node *n1, node *n2) {
    if (n1->v != n2->v) return false;
    if (n1->children.size() != n2->children.size()) return false;

    for (int i = 0; i < n1->children.size(); ++i) {
        if (!eq(n1->children[i], n2->children[i]))return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    auto ps = pmatch(s);
    auto pt = pmatch(t);

    node* tree_a = parse(s, ps, 0, s.length());
    node* tree_b = parse(t, pt, 0, t.length());
    cout << (eq(tree_a, tree_b) ? "Yes": "No") << endl;
}
