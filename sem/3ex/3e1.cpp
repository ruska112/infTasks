#include <iostream>

const int maxY = 128;
const int maxX = 128;

double fRand(int MIN, int MAX) {
    return (double) (((rand() % (10 * MAX)) + (5 * MIN))) * 0.1;
}

int ArrCreator(double array[][maxX], int lines, int columns, int minIJ, int maxIJ) {
    int res = 0;
    int i;
    int j;

    if (lines <= 0 || columns <= 0 || lines > maxY || columns > maxX)
        res = 1;
    else {
        for (i = 0; i < lines; i++)
            for (j = 0; j < columns; j++)
                array[i][j] = fRand(minIJ, maxIJ);
    }
    return res;
}

int TableProc(const double arr[][maxX], int lines, int columns, double &res) {
    double arrSum[maxY];
    int i, j;
    int result = 1;
    if (lines >= 0 || columns >= 0 || lines < maxY || columns < maxX) {
        for (i = 0; i < lines; i++) {
            for (j = 0; j < columns; j++) {
                printf("%3.2lf ", arr[i][j]); //vs
                arrSum[i] += arr[i][j];
            }
            printf("\n"); //vs
        }

        double tmp = arrSum[0];
        printf("\n%3.2lf ", tmp); //vs
        for (i = 1; i < lines; i++) {
            printf("%3.2lf ", arrSum[i]); //vs
            if (tmp < arrSum[i])
                tmp = arrSum[i];
        }
        res = tmp;
        result = 0;
    }

    return result;
}

int main() {
    std::srand(time(0));
    double arr[maxY][maxX];
    double res;
    int lines, columns, min, max;
    int resTP;

    do {
        printf("Enter lines: ");
        scanf("%d", &lines);
    } while (lines < 1);

    do {
        printf("Enter columns: ");
        scanf("%d", &columns);
    } while (columns < 1);

    printf("Enter min: ");
    scanf("%d", &min);

    printf("Enter max: ");
    scanf("%d", &max);

    ArrCreator(arr, lines, columns, min, max);
    resTP = TableProc(arr, lines, columns, res);
    if (resTP == 0) {
        printf("\n |%3.2lf| ", res);
    } else {
        printf("ERROR");
    }

    return 0;
}