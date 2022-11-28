#include <stdio.h>

int main()
{
    int *p;
    int n = 10;
    int k = 0;
    p = &n;

    printf("n = %d, p = %p\n", n, p);
    k=*p++;
    printf("%d %u %u", k, &n, &p);
    /*printf("n = %d, p = %p\n", n, p);
    (*p)++;
    printf("n = %d, p = %p\n", n, p);
    *++p;
    printf("n = %d, p = %p\n", n, p);
    ++*p;
    printf("n = %d, p = %p\n", n, p);*/

    return 0;
}