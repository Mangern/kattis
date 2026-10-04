#include<bits/stdc++.h>
using namespace std;

constexpr int c = 95238;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int &i : v) cin >> i;

    sort(v.begin(), v.end());
    
    unordered_map<int, int> cnt;
    for (int i: v)
    {
        i = i + c;
        if (cnt.count(i) == 0) cnt[i] = 1;
        else cnt[i]++;
    }

    vector<int> output;

    for (int i = 1; i <= n / 2; i++)
    {
        int diff = v[i] - v[0];
        if (diff == 0) continue;
        if (!output.empty() && output.back()  == diff) continue;

        unordered_map<int, int> n_cnt = cnt;
        bool possible = true;
        for (int y : v)
        {
            y = y +c;
            if (n_cnt[y] > 0)
            {
                if (n_cnt[y+diff] > 0) 
                {
                    n_cnt[y]--;
                    n_cnt[y+diff]--;
                } else {
                    possible = false; 
                    break;
                }
            }
        }
        if (possible) output.push_back(diff);
    }

    cout << output.size() << "\n";
    for (int i: output) cout <<i  << "\n";
}
