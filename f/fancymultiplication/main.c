#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    int64_t a, b;
    scanf("%" SCNi64 "%" SCNi64, &a, &b);
    int64_t result = 0;

    for (int64_t i = 0; i < b; ++i) {
        result += a;
    }
    printf("%" PRIi64 "\n", result);
}
