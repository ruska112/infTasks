#include <iostream>
#include <cmath>

int CircleInEqual(double a, double b, double r, int &count) {
    int x, y;
    int result = 1;
    if (r > 0) {
        for (x = ceil(a - r); x <= floor(a + r); x++)
            for (y = ceil(b - r); y <= floor(b + r); y++)
                if ((x - a) * (x - a) + (y - b) * (y - b) <= r * r)
                    count++;
        result = 0;
    }
    return result;
}

int main() {
    double a, b, r;
    int count = 0;

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter r: ");
    scanf("%lf", &r);

    int funcRes = CircleInEqual(a, b, r, count);

    if (funcRes == 0) {
        printf("Count of int dots in circle: %d", count);
    } else {
        printf("Error with function");
    }
    return 0;
}
