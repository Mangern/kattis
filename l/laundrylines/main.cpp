#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    const int diff_bits = 10; // 1024
    vector<int> dp(1 << (n+diff_bits), 1e6);
    vector<bool> processed(1 << (n+diff_bits), false);
    vector<int> states = {0};
    vector<int> next_states;
    dp[0] = 0;
    for (int hanged = 0; hanged < n; hanged++) {
        //cout << "------ " << hanged << endl;
        for (int i : states) {
            //cout << i << " " << dp[i] << endl;
            if (processed[i]) continue;
            processed[i] = true;

            int diff = i % (1 << diff_bits);

            for (int k = 0; k < n; k++) {
                if (((1 << (k+diff_bits)) & i) == 0) {
                    int next_state = (i | (1 << (k+diff_bits))) - diff;
                    int diff1 = diff + w[k];
                    if (diff1 < (1 << diff_bits)) {
                        int state1 = next_state+diff1;
                        dp[state1] = min(dp[state1], max(dp[i], diff1));
                        next_states.push_back(state1);
                    }
                    int diff2 = abs(diff-w[k]);
                    if (diff2 < (1 << diff_bits)) {
                        int state2 = next_state+diff2;
                        dp[state2] = min(dp[state2], max(dp[i], diff2));
                        next_states.push_back(state2);
                    }
                }
            }
        }
        swap(states, next_states);
        next_states = {};
    }

    int best = 1e6;
    for (int i : states) {
        best = min(best, dp[i]);
    }

    cout << best << "\n";
}
