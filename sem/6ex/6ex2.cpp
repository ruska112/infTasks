#include <stdio.h>

int fact(int num)
{
    if (num == 0 || num == 1)
        return 1;

    return num * fact(num - 1);
}

int main()
{
    int n, k, Cnk;

    printf("Enter n:\n");
    scanf("%d", &n);

    printf("Enter k:\n");
    scanf("%d", &k);

    Cnk = fact(n) / (fact(k) * fact(n - k));

    printf("%d\n", Cnk);

    return 0;
}
