#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define sz(v) (int)(v).size()

char buf[2000005];

vi Z(const string& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	for(int i = 1; i < S.size(); ++i) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

struct Node {
    int dp;
    map<char,Node*> next;
    Node() {
        dp = 0;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    Node* root = new Node();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        string s(buf);

        int m = sz(s);
        vi z = Z(s);

        vi good_lens;
        for (int l = 1; l < m; ++l) {
            if (z[m-l] == l) {
                good_lens.push_back(l);
            }
        }
        good_lens.push_back(m);
        Node* ptr = root;
        int l_ptr = 0;
        int dp_here = 1;
        for (int i = 0; i < m; ++i) {
            char c = s[i];
            if (!ptr->next.count(c)) {
                ptr->next[c] = new Node();
            }
            ptr = ptr->next[c];
            while (good_lens[l_ptr] < i + 1)++l_ptr;
            if (good_lens[l_ptr] == i + 1) {
                dp_here = max(dp_here, ptr->dp + 1);
            }
        }
        ptr->dp = dp_here;
        ans = max(ans, dp_here);
    }
    printf("%d\n", ans);
}
