#include <iostream>

int CountCharInInt(int NumFU, int floor, int &count) {
    int result = 1;
    if (floor > 1) {
        if (NumFU < 0) {
            NumFU = -NumFU;
        }

        while (NumFU != 0) {
            NumFU /= floor;
            count++;
        }
        result = 0;
    }
    return result;
}

int main() {
    int number, floor;
    int count = 0;

    printf("Enter int number: ");
    scanf("%d", &number);

    printf("Enter base of notation: ");
    scanf("%d", &floor);

    int funcRes = CountCharInInt(number, floor, count);

    if (funcRes == 0) {
        printf("Count of digits in a number: %d", count);
    } else {
        printf("Error with function");
    }
    return 0;
}
