#include <stdio.h>

#define mxN 1005

long a[mxN];
long b[mxN];
long n;

int main() {
  scanf("%ld", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%ld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%ld", &b[i]);
  }

  long l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] > b[j])++l;
      if (b[j] > a[i])++r;
    }
  }

  if (l > r) {
    printf("first\n");
  } else if (l < r) {
    printf("second\n");
  } else {
    printf("tie\n");
  }
}
