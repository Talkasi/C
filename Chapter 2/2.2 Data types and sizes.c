#include <float.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    printf("CHARS.");
    printf(">> For chars by computing.\n");
    char_det();
    s_char_det();
    u_char_det();

    printf("\n>> For chars from headers.\n");
    printf("Char range:             from %d to %d.\n", CHAR_MIN, CHAR_MAX);
    printf("Signed char range:      from %d to %d.\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range:    from %d to %d.\n", 0, UCHAR_MAX);


    printf("\n\nSHORTS.\n>> For shorts by computing.\n");
    short_det();
    s_short_det();
    u_short_det();

    printf("\n>> For shorts from headers.\n");
    printf("Shorts range:             from %d to %d.\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned shorts range:    from %d to %d.\n", 0, USHRT_MAX);


    printf("\n\nINTS.\n>> For ints by computing.\n");
//    int_det();
//    s_int_det();
//    u_int_det();

    printf("\n>> For ints from headers.\n");
    printf("Ints range:             from %d to %d.\n", INT_MIN, INT_MAX);
    printf("Unsigned ints range:    from %u to %u.\n", 0, UINT_MAX);

    printf("\n>> For longs from headers.\n");
    printf("longs range:             from %ld to %ld.\n", LONG_MIN, LONG_MAX);
    printf("Unsigned longs range:    from %u to %lu.\n", 0, ULONG_MAX);

    printf("\n>> For long longs from headers.\n");
    printf("long longs range:             from %lld to %lld.\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned long longs range:    from %u to %llu.\n", 0, ULLONG_MAX);

}

int char_det()
{
    char char_var, char_max = -1000, char_min = 1000;

    for (int i = -1000; i < 1001; ++i) {
        char_var = i;
        if (char_var > char_max)
            char_max = char_var;
        if (char_var < char_min)
            char_min = char_var;
    }

    printf("Char range:             from %d to %d. Circling overflowing: ..., 127, -128, ...;\n", char_min, char_max);
}

int s_char_det()
{
    signed char char_var, char_max = -1000, char_min = 1000;

    for (int i = -1000; i < 1001; ++i) {
        char_var = i;
        if (char_var > char_max)
            char_max = char_var;
        if (char_var < char_min)
            char_min = char_var;
    }

    printf("Signed char range:      from %d to %d. Circling overflowing: ..., 127, -128, ...;\n", char_min, char_max);
}

int u_char_det()
{
    unsigned char char_var, char_max = -1000, char_min = 1000;

    for (int i = -1000; i < 1001; ++i) {
        char_var = i;
        if (char_var > char_max)
            char_max = char_var;
        if (char_var < char_min)
            char_min = char_var;
    }

    printf("Unsigned char range:    from %d to %d. Circling overflowing: ..., 255, 0, ...;\n", char_min, char_max);
}

int short_det()
{
    short short_var, short_max = -1000000, short_min = 1000000;

    for (int i = -1000000; i < 1000001; ++i) {
        short_var = i;
        if (short_var > short_max)
            short_max = short_var;
        if (short_var < short_min)
            short_min = short_var;
    }

    printf("Short range:             from %d to %d. Circling overflowing: ..., 32767, -32768, ...;\n", short_min, short_max);
}

int s_short_det()
{
    signed short short_var, short_max = -1000000, short_min = 1000000;

    for (int i = -1000000; i < 1000001; ++i) {
        short_var = i;
        if (short_var > short_max)
            short_max = short_var;
        if (short_var < short_min)
            short_min = short_var;
    }

    printf("Signed short range:      from %d to %d. Circling overflowing: ..., 32767, -32768, ...;\n", short_min, short_max);
}

int u_short_det()
{
    unsigned short short_var, short_max = -1000000, short_min = 1000000;

    for (int i = -1000000; i < 1000001; ++i) {
        short_var = i;
        if (short_var > short_max)
            short_max = short_var;
        if (short_var < short_min)
            short_min = short_var;
    }

    printf("Unsigned short range:    from %d to %d. Circling overflowing: ..., 65535, 0 , ...;\n", short_min, short_max);
}

int int_det()
{
    int int_var, int_max = -10000000000, int_min = 10000000000;

    for (long i = -10000000000; i < 10000000001; ++i) {
        int_var = i;
        if (int_var > int_max)
            int_max = int_var;
        if (int_var < int_min)
            int_min = int_var;
    }

    printf("Int range:              from %d to %d.\n", int_min, int_max);
}

int s_int_det()
{
    signed int int_var, int_max = -10000000000, int_min = 10000000000;

    for (long i = -10000000000; i < 10000000001; ++i) {
        int_var = i;
        if (int_var > int_max)
            int_max = int_var;
        if (int_var < int_min)
            int_min = int_var;
    }

    printf("Signed int range:       from %d to %d.\n", int_min, int_max);
}

int u_int_det()
{
    unsigned int int_var, int_max = -10000000000, int_min = 10000000000;

    for (long i = -10000000000; i < 10000000001; ++i) {
        int_var = i;
        if (int_var > int_max)
            int_max = int_var;
        if (int_var < int_min)
            int_min = int_var;
    }

    printf("Unsigned int range:     from %u to %u.\n", int_min, int_max);
}