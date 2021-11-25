#include <iostream>
#include <cmath>

void SquareInEqual(double a, double b, double c, int &count) {
    double x1, x2;
    double D = ((b * b) - (4 * a * c));

    if (D >= 0) {
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
        if (x1 > x2) {
            double tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if (a > 0) {
            if (x1 != x2) {
                for (int i = ceil(x1); i <= floor(x2); i++) {
                    count++;
                }
            } else {
                count++;
                printf("x1 == x2 == %2.1lf\n", x1);
            }
        } else {
            if (x1 != x2) {
                printf("Infinitely many roots except from %2.1lf to %2.1lf\n", x1, x2);
            } else {
                count++;
                printf("x1 == x2 == %2.1lf\n", x1);
            }
        }
    } else {
        printf("Discriminant less than 0 (D = %lf )\n", D);
        if (a > 0) {
            printf("No roots\n");
        } else {
            printf("Infinitely many roots\n");
        }
    }
}

int main() {
    double a, b, c;
    int count = 0;

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter c: ");
    scanf("%lf", &c);

    SquareInEqual(a, b, c, count);
    printf("Count of int dots: %d", count);

    return 0;
}
