#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ks(n);
    for (auto& x : ks)cin >> x;
    vector<int> a(n);
    iota(begin(a), end(a), 1);

    int cur = 0;
    for (int it = 0; it < n - 1; ++it) {
        int k = ks[a[cur] - 1];

        int nxt = (cur + k - 1) % a.size();

        a.erase(a.begin() + nxt);
        cur = nxt % a.size();
    }
    cout << a[0] << endl;
}
