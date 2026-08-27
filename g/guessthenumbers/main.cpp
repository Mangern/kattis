#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    char op = 0;
    node *lhs = 0, *rhs = 0;

    node() {
        lhs = NULL;
        rhs = NULL;
    }
};

int lptr;
string s;
vector<ll> v;

node* parse() {
    if (s[lptr] == '(') {
        ++lptr;
        node* ret = new node();
        ret->lhs = parse();
        ret->op = s[lptr];
        ++lptr;
        ret->rhs = parse();
        assert(s[lptr] == ')');
        ++lptr;
        return ret;
    }

    if ('a' <= s[lptr] && s[lptr] <= 'z') {
        node* ret = new node();
        ret->op = s[lptr];
        ++lptr;
        return ret;
    }

    assert(false);
}

void print_tree(node* tree, int indent = 0) {
    for (int i = 0; i < indent; ++i)cout << " ";
    cout << tree->op << endl;

    if (tree->lhs != NULL) {
        print_tree(tree->lhs, indent + 2);
        print_tree(tree->rhs, indent + 2);
    }

}

int ptr;

ll evaluate(node* tree) {
    if (tree->lhs != NULL) {
        ll l = evaluate(tree->lhs);
        ll r = evaluate(tree->rhs);

        switch(tree->op) {
            case '*':
                return l * r;
            case '-':
                return l - r;
            case '+':
                return l + r;
        }
        assert(false);
    }

    return v[ptr++];
}

void test() {
    int n;
    cin >> n;
    if (!n) {
        cin >> n;
        exit(0);
    }

    v.assign(n, 0);
    for (auto &x : v) {
        cin >> x;
    }

    sort(begin(v), end(v));

    ll m;
    cin >> m;

    cin >> s;

    lptr = 0;
    node* tree = parse();

    do {
        ptr = 0;
        ll ret = evaluate(tree);

        if (ret == m) {
            cout << "YES" << endl;
            return;
        }

    } while (next_permutation(begin(v), end(v)));
    cout << "NO" << endl;
}

int main() {
    for (;;) test();
}
