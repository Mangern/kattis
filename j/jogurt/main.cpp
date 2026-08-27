#include <iostream>
#include <stack>
#include <cassert>

using namespace std;
using ll = long long;

struct node {
    int val;
    node* lft;
    node* rgt;
};

node* copytree(node* tree) {
    if (tree == nullptr)return nullptr;
    return new node{
        tree->val,
        copytree(tree->lft),
        copytree(tree->rgt)
    };
}

void mul2(node* tree) {
    if (tree == nullptr)return;
    tree->val *= 2;
    mul2(tree->lft);
    mul2(tree->rgt);
}

void add1(node* tree, bool leaf) {
    if (tree->lft == nullptr) {
        if (leaf)tree->val++;
    } else {
        if (!leaf)tree->val++;
        add1(tree->lft, leaf);
        add1(tree->rgt, leaf);
    }
}

node* solve(ll n) {
    if (n == 1) {
        return new node{1, nullptr, nullptr};
    }

    node* lft = solve(n - 1);

    mul2(lft);

    node* rgt = copytree(lft);

    add1(lft, true);
    add1(rgt, false);

    return new node{
        1,
        lft,
        rgt
    };
}

void preorder(node* tree) {
    if (tree == nullptr)return;
    cout << tree->val << " ";
    preorder(tree->lft);
    preorder(tree->rgt);
}

int main() {
    ll n;
    cin >> n;

    node* result = solve(n);
    preorder(result);
    cout << endl;
}
