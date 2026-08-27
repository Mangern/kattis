#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include <set>
#include <array>

using namespace std;

int main() {
    int n = 200000;
    int c = n;

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> dist(1, n);

    vector<int> pruf;
    set<int> leaf;
    for (int i = 1; i <= n; ++i)leaf.insert(i);

    for (int i = 0; i < n - 2; ++i) {
        pruf.push_back(dist(generator));
        leaf.erase(pruf.back());
    }

    vector<bool> lst(n-2, 0);

    set<int> seen;

    for (int i = n - 3; i >= 0; --i) {
        if (!seen.count(pruf[i]))lst[i] = 1;
        seen.insert(pruf[i]);
    }

    vector<array<int,2>> edge;

    for (int i = 0; i < n - 2; ++i) {
        int u = pruf[i];

        int v = *leaf.begin();
        edge.push_back({u, v});
        leaf.erase(v);

        if (lst[i])leaf.insert(u);
    }

    edge.push_back({*leaf.begin(), *++leaf.begin()});


    vector<int> w(c), h(c);
    iota(begin(w), end(w), 1);
    iota(begin(h), end(h), 1);


    shuffle(begin(w), end(w), generator);
    shuffle(begin(h), end(h), generator);

    cout << n << " " << c << endl;
    for (auto [u, v] : edge)cout << u << " " << v << endl;

    for (int i = 0; i < c; ++i) {
        cout << w[i] << " " << h[i] << endl;
    }

}
