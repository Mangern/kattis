#include <algorithm>
#include <bitset>
#include <iterator>
#include <numeric>
#include <set>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define all(v) begin(v), end(v)

int main() {
    int n;
    cin >> n;

    vector<int> vec(n, 0);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (char c : s) {
            vec[i] |= (1<<(c-'A'));
        }
    }

    sort(all(vec));


    int ans = 1e9;
    do {
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            cnt += __builtin_popcount(vec[i] & vec[i-1]);
            //if (cnt > ans)break;
        }
        ans = min(ans, cnt);
    } while (next_permutation(all(vec)));
    cout << ans << endl;
}
