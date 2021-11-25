#include <iostream>

int CountCharAftDot(int NumFU, int floor, int k, int &count) {
    int result = 1;
    if (floor > 1 && k > 0) {
        if (NumFU < 0) {
            NumFU = -NumFU;
        }

        double num = 1. / NumFU;

        for (int i = 0; i < k; i++) {
            num *= floor;
            int tmp = num;

            if (tmp % 2 == 1) {
                count++;
            }
            num -= tmp;
        }
        result = 0;
    }
    return result;
}

int main() {
    int number, floor, k;
    int count = 0;

    printf("Enter int number: ");
    scanf("%d", &number);

    printf("Enter base of notation: ");
    scanf("%d", &floor);

    printf("Enter count of characters to check: ");
    scanf("%d", &k);

    int funcRes = CountCharAftDot(number, floor, k, count);

    if (funcRes == 0) {
        printf("Count of digits in a number after dot: %d", count);
    } else {
        printf("Error with function");
    }
    return 0;
}
