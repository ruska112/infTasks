#include <random>
#include <ctime>

double fRand(int MIN, int MAX) {
    return (double) (((rand() % (10 * MAX)) + (5 * MIN))) * 0.1;
}

int averageValue(double arr[], int count, int n, double &av) {
    /* Функция вычисляет среднее арифметическое
     *      одномерного статистического массива
     *      вещественных чисел
     *
     * Входные параметры:
     * arr  - массив максимального размера count
     * n    - реальный размер
     *
     * Выходной параметр:
     * av - искомое среднее арифметическое
     *
     * Функция возвращает :
     * 0 в случае успешного выполнения
     * 1 если размер массива оказался некорректным,
     *      в этом случае av неопределенно
     */

    int res = 0;

    if (n < 1 || n > count) {
        res = 1;
    } else {
        for (int i = 0; i < n; ++i) {
            av += arr[i];
        }
        av /= n;
    }

    return res;
}

int main() {
    const int count = 20;
    double array[count], averageX;
    int n, minArr, maxArr;

    do {
        printf("Enter count of values lower than 20: ");
        scanf("%d", &n);
    } while (n < 1 || n > count);

    printf("Enter minimal value in array: ");
    scanf("%d", &minArr);
    printf("Enter max value in array: ");
    scanf("%d", &maxArr);

    std::srand(time(0));

    for (int i = 0; i < n; i++) {
        array[i] = fRand(minArr, maxArr);
        printf("%.2lf ", array[i]);
    }

    int some = averageValue(array, count, n, averageX);

    if (some == 0) {
        printf("\n%lf", averageX);
    } else {
        printf("error");
    }

    return 0;
}
