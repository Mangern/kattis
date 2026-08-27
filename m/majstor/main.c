#include <stdio.h>
#include <stdlib.h>

int r, n;
char played[50];

char* friend[50];

int cnt[3];

int get_index(char c) {
    if (c == 'R')  return 0;
    if (c == 'P')  return 1;
  /*if (c == 'S')*/return 2;
}

int score(char a, char b) {
    if (a == b)return 1;
    int ia = get_index(a);
    int ib = get_index(b);

    if (ia == (ib+1)%3)return 2;
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &r);
    scanf("%s", played);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        friend[i] = (char*)malloc(r * sizeof(char));
        scanf("%s", friend[i]);
    }

    int actual = 0, best = 0;

    for (int i = 0; i < r; ++i) {
        cnt[0] = 0;
        cnt[1] = 0;
        cnt[2] = 0;

        for (int j = 0; j < n; ++j) {
            actual += score(played[i], friend[j][i]);

            cnt[get_index(friend[j][i])] += 1;
        }

        int best_score = 0;
        best_score = max(best_score, cnt[0] + 2 * cnt[2]);
        best_score = max(best_score, cnt[1] + 2 * cnt[0]);
        best_score = max(best_score, cnt[2] + 2 * cnt[1]);
        best += best_score;
    }

    printf("%d\n%d\n", actual, best);

    for (int i = 0; i < n; ++i) {
        free(friend[i]);
    }
    return 0;
}
