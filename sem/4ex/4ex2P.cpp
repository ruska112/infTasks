#include <iostream>

int matrixRepacer (double *a, int n, int m) {
    int result = 0;

    int i, j;
    bool negIs = false;
    int negColCount = 0;
    int posRowCount = 0;
    double rowSum = 0;
   
    if ( n > 0 && m > 0 && a != NULL ) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                rowSum += a[i*m + j];
            }
            if (rowSum > 0) {
                posRowCount++;
            }
            rowSum = 0;
        }

        for (i = 0; i < m; i++) {
          for (j = 0; j < n; j++) {
              if (a[j*n + i] < 0) {
              negIs = true;
                }
           }
          if (negIs) {
              negColCount++;
          }
          negIs = false;
      }

        printf("%d  %d \n", negColCount, posRowCount);     
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

int main() {
    int n, m;
    int i, j;

    int funcRes;

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
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%3.1lf ", a[i*m + j]);
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

        delete[] a;
    } else {
        printf("\nSomething wrong with array!\n");
    }
    return 0;
}
