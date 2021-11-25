#include <random>
#include <ctime>

double fRand(int MIN, int MAX) {
    return (double) (rand() % (50 * (MAX - MIN)) + 10 * MIN) * .01;
}

int main() {
    const int count = 10;
    double array[count], minX;

    std::srand(time(0));

    for (int i = 0; i < count; i++) {
        array[i] = fRand(-10, 10);
        printf("%.2lf, ", array[i]);
    }

    minX = array[0];

    for (int i = 1; i < count; ++i)
        if (array[i] < minX)
            minX = array[i];

    printf("\n Minimal value is: %.2lf", minX);
    return 0;
}
