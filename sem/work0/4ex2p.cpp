#include <iostream>

const int maxRow = 128;
const int maxCol = 128;

int matrixRepacer (double **a, int n, int m);

int main() {
    int n, m;
    int i, j;

    int funcRes;

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



    double** a =
        new double*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new double[m];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("[%d][%d]", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3.1lf ", a[i][j]);
        }
        printf("\n");
    }

    funcRes = matrixRepacer(a, n, m);

    if (funcRes == 1) {
        printf("Column with negative element greater than row with positive sum\n");
    } else if (funcRes == 2) {
        printf("Column with negative element less than row with positive sum\n");
    } else if (funcRes) {
        printf("Column with negative element equal with row with positive sum\n");
    } else {
        printf("\nError\n");
    }

    for (i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}



int matrixRepacer (double **a, int n, int m) {
    int result = 0;

    int i, j;

    int negColCount = 0;
    int posRowCount = 0;
    double rowSum = 0;
   
    if ( n > 0 && n < maxRow && m > 0 && m < maxCol ) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (a[j][i] < 0) {
                    negColCount++;
                }
                rowSum += a[i][j];
            }

            if (rowSum > 0) {
                posRowCount++;
            }
            rowSum = 0;
        }
     
        if (negColCount > posRowCount) {
            result = 1;
        } else if (posRowCount > negColCount) {
            result = 2;
        } else {
            result = 3;
        }
    }

    return result;
}

