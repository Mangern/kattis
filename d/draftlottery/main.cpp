#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> team(n);
    unordered_map<string, int> tid;

    vector<int> balls(n);

    int tot_balls = 0;

    for (int i = 0; i < n; ++i) {
        cin >> balls[i] >> team[i];
        tid[team[i]] = i;

        tot_balls += balls[i];
    }

    vector<vector<double>> prob(n, vector<double>(n, 0.0));

    for (int fst = 0; fst < n; ++fst) {
        for (int scn = 0; scn < n; ++scn) if (scn != fst) {
            for (int trd = 0; trd < n; ++trd) if (trd != scn && trd != fst) {
                double here = (double)balls[fst] / (double)tot_balls 
                            * (double)balls[scn] / (double)(tot_balls - balls[fst]) 
                            * (double)balls[trd] / (double)(tot_balls - balls[fst] - balls[scn]);
                prob[fst][0] += here;
                prob[scn][1] += here;
                prob[trd][2] += here;

                int ind = 3;
                for (int i = 0; i < n; ++i) {
                    if (i == fst) continue;
                    if (i == scn) continue;
                    if (i == trd) continue;
                    prob[i][ind++] += here;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            prob[i][j] += prob[i][j-1];
        }
    }

    int q;
    cin >> q;
    while (q-->0) {
        int k;
        string s;
        cin >> s;
        cin >> k;

        cout << setprecision(12) << fixed << prob[tid[s]][k-1] << endl;
    }
}
