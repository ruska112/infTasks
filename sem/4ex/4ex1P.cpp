#include <iostream>

int matrixRepacer (double *a, int n, int m, int &res) {
    int i, j;
    int result = 1;
    bool decrease = true;
    int decreaseRowCount = 0;

    if ( n > 0 && m > 0 && a != NULL) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m-1; j++) {
                if ( a[i*m + j] <= a[i*m + (j+1)] && decrease ) {
                    decrease = true;
                } else {
                    decrease = false;
                }
            }
            if (decrease) {
                decreaseRowCount++;
            }
            decrease = true;
        }

        res = decreaseRowCount;

        result = 0;
    }

    return result;
}

int main() {

    int n, m, res, funcRes;
    int i, j;

    do {
        system("clear");
        printf("Enter count of row: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        system("clear");
        printf("Enter count of column: ");
        scanf("%d", &m);
    } while (m <= 0);

    double* a = new double [n * m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("[%d][%d]", i, j);
            scanf("%lf", &a[i*m + j]);
        }
    }

    if (a != NULL) {

        funcRes = matrixRepacer(a, n, m, res);

        if (funcRes == 0) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    printf("%3.1lf ", a[i*m + j]);
                }
                printf("\n");
            }

            printf("\nCount of lines sorted in non-decreasing order: %d\n", res);
        } else {
            printf("\nError!\n");
        }

        delete[] a;
    } else {
        printf("\nSomethingwrong with array!\n");
    }

    return 0;
}
