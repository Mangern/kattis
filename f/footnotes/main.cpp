#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)

const int mxN = 1e6+6;

char s[mxN];

int main() {
    scanf("%s", s);

    int n = strlen(s);

    vector<int> istack;
    vector<int> cstack;

    vector<int> match(n, -1);
    vector<int> count(n, -1);

    int tot = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            istack.push_back(i);
            cstack.push_back(0);
            continue;
        }
        if (s[i] == ')') {
            int cnt = cstack.back();
            match[istack.back()] = i;
            count[istack.back()] = cnt;
            istack.pop_back();
            cstack.pop_back();

            if (cstack.size()) {
                cstack.back() += cnt;
            }
            continue;
        }

        ++tot;
        if (cstack.size())++cstack.back();
    }
    if (tot % 3 != 0) {
        printf("impossible\n");
        return 0;
    }

    int n1 = tot / 3;
    int n2 = 2 * n1;
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
        if (match[i] != -1) {
            if (count[i] == n1)idx.push_back(i);
        }
    }
    int m = idx.size();

    for (int i = 0; i < n; ++i) {
        if (count[i] == n1) {
            int j = lower_bound(all(idx), match[i]) - begin(idx);
            if (j < m) {
                string ans1, ans2, ans3;
                j = idx[j];
                for (int k = 0; k < i; ++k) {
                    ans1.push_back(s[k]);
                }
                ans1 += "[1]";
                for (int k = match[i] + 1; k < j; ++k) {
                    ans1.push_back(s[k]);
                }
                ans1 += "[2]";
                for (int k = match[j] + 1; k < n; ++k) {
                    ans1.push_back(s[k]);
                }
                ans2 = "[1] ";
                for (int k = i + 1; k < match[i]; ++k) {
                    ans2.push_back(s[k]);
                }
                ans3 = "[2] ";
                for (int k = j + 1; k < match[j]; ++k) {
                    ans3.push_back(s[k]);
                }
                printf("%s\n%s\n%s\n", ans1.c_str(), ans2.c_str(), ans3.c_str());
                return 0;
            }
        } else if (count[i] == n2) {
            int j = lower_bound(all(idx), i) - begin(idx);
            if (j < m && idx[j] < match[i]) {
                j = idx[j];
                string ans1, ans2, ans3;
                for (int k = 0; k < i; ++k) {
                    ans1.push_back(s[k]);
                }
                ans1 += "[1]";
                for (int k = match[i] + 1; k < n; ++k) {
                    ans1.push_back(s[k]);
                }
                ans2 = "[1] ";
                for (int k = i + 1; k < j; ++k) {
                    ans2.push_back(s[k]);
                }
                ans2 += "[2]";
                for (int k = match[j] + 1; k < match[i]; ++k) {
                    ans2.push_back(s[k]);
                }
                ans3 = "[2] ";
                for (int k = j + 1; k < match[j]; ++k) {
                    ans3.push_back(s[k]);
                }
                printf("%s\n%s\n%s\n", ans1.c_str(), ans2.c_str(), ans3.c_str());
                return 0;
            }
        }
    }
    printf("impossible\n");
}
