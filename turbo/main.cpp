#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename t = long long>
struct FenwickTree {
    int n;
    vector<t> tree;
    FenwickTree(int _n) {
        n = _n+1;
        tree = vector<t>(n, t(0));
    }

    t query(int i) {
        ++i;

        t sum(0);
        for (; i > 0; i -= (i & (-i)))sum += tree[i];
        return sum;
    }

    t query(int i, int j) {
        return query(j) - query(i-1);
    }

    void add(int i, t val) {
        ++i;
        for (; i < n; i += (i & (-i))) {
            tree[i] += val;
        }
    }
};


int main() {
    int n;
    cin >> n;

    FenwickTree<int> ft(n); // query(i) -> how many to the left of i
    for (int i = 1; i < n; ++i)ft.add(i, 1);
    vector<int> pos(n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        --arr[i];
        pos[arr[i]] = i;
    }

    sort(arr.begin(), arr.end());
    int l = 0;
    int r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            int cur = arr[r];

            int lft = ft.query(pos[cur]);

            int rgt = n - i - lft - 1;

            cout << rgt << "\n";

            ft.add(pos[cur]+1, -1);

            --r;
        } else {
            int cur = arr[l];
            int lft = ft.query(pos[cur]);
            cout << lft << "\n";
            ft.add(pos[cur]+1, -1);
            ++l;
        }
    }
}
