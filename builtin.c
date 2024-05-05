 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long num = 1LL << 62LL;
    int clz = 0;
    int ctz = 0;
    int ones = 0;

    printf("sizeof long long = %lu\n", sizeof(long));

    clz = __builtin_clz(num);
    printf("Number of leading zero's in %llu is %d\n", num, clz);

    clz = __builtin_clz(-num);
    printf("Number of leading zero's in %llu is %d\n", -num, clz);

    ctz = __builtin_ctz(num);
    printf("Number of trailing zero's in %llu is %d\n", num, ctz);

    ones = __builtin_popcount(num);
    printf("Number of one's in %llu is %d\n", num, ones);

    return 0;
}
