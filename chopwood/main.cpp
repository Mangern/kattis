#include <iostream>
#include <set>
#include <vector>
#include <array>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n; ++n;

    vector<int> pruf(n - 2);
    set<int> leaf;
    for (int i = 1; i <= n; ++i)leaf.insert(i);
 
    for (auto& x : pruf) {
        cin >> x;
        leaf.erase(x);
    }
    int last;
    cin >> last;
 
    vector<bool> lst(n - 2, 0);
 
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
 

    if ((*++leaf.begin()) != last) {
        cout << "Error" << endl;
        return 0;
    }
 
    for (auto [u, v] : edge)cout << v << endl;
    cout << *leaf.begin() << endl;
 
    return 0;
}
