#include <stdio.h>
#include <string.h>

char buf[2000006];

char ans[2000006];

int main() {
    int n;
    scanf("%d", &n);

    int ptr = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        int l = strlen(buf);
        strncpy(&ans[ptr], buf, l);
        ptr += l;
    }

    for (int i = ptr - 1; i >= 0; --i) {
        printf("%c", ans[i]);
    }
    puts("");
}
