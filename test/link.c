#include <stdio.h>

int main(void)
{

    int a = 6;

    int aptr = *a;

    printf("%d", &aptr);

    return 0;
}