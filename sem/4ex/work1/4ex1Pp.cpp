#include <iostream>

const int maxRow = 128;
const int maxCol = 128;

int matrixRepacer (double *a, int n, int m, int &res) {
    int i, j;

    int result = 1;

    bool decrease = true;
    
    int decreaseRowCount = 0;

    if ( n > 0 && n < maxRow && m > 0 && m < maxCol ) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m-1; j++) {
                if ( a[i*8 + j] <= a[i*8 + (j+1)] && decrease ) {
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

    const int maxRow = 128;
    const int maxCol = 128;

    int n, m, res, funcRes;
    int i, j;

    do {
        system("clear");
        printf("Enter count of row: ");
        scanf("%d", &n);
    } while (n <= 0 || n > maxRow);

    do {
        system("clear");
        printf("Enter count of column: ");
        scanf("%d", &m);
    } while (m <= 0 || m > maxCol);

    double* a = new double [n * m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("[%d][%d]", i, j);
            scanf("%lf", &a[i*8 + j]);
        }
    }

    funcRes = matrixRepacer(a, n, m, res);

    if (funcRes == 0) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%3.1lf ", a[i*8 + j]);
            }
            printf("\n");
        }

        printf("\nCount of lines sorted in non-decreasing order: %d\n", res);
    } else {
        printf("\nError!\n");
    }

    delete[] a;

    return 0;
}
