#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

// char, int, unsigned, long long, short, int32_t, int64_t
int main()
{
    printf("%d\n", CHAR_MAX);
    printf("%d\n", INT_MAX);
    printf("%u\n", UINT_MAX);
    printf("%lld\n", LLONG_MAX);
    printf("%d\n", SHRT_MAX);
    printf("%"PRId32"\n", INT32_MAX);
    printf("%"PRId64"\n", INT64_MAX);

    return 0;
}