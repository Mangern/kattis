#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int ans = 0;

    while (ms.size()) {
        ++ans;
        int card = *ms.begin();
        ms.erase(ms.begin());

        while (ms.count(card + 1)) {
            ms.erase(ms.find(card + 1));
            ++card;
        }
    }
    cout << ans << endl;
}
