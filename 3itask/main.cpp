#include <iostream>

void print_menu()
{
    system("clear");
    printf("What do you want to do?\n");
    printf("1. Create table\n");
    printf("    2. Hand input\n");
    printf("    3. Rand input\n");
    printf("    4. File input\n");
    printf("5. Show table\n");
    printf("6. Process table\n");
    printf("7. Show result\n");
    printf("8. Exit\n");
}

int get_variant(int count)
{
    int variant;
    char s[127];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
    {
        system("clear");
        printf("Incorrect input. Try again...\n");
        printf(">");
        scanf("%s", s);
    }

    return variant;
}

int main()
{
    int count = 8;

    print_menu();

    int var = get_variant(count);

    printf("---%d---\n", var);

    return 0;
}