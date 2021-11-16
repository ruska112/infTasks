#include <iostream>

typedef double* doubleptr;

int main() {

    const int maxRow = 128;
    const int maxCol = 128;

    int n, m;
    int i, j;

    int negColCount = 0;
    int posRowCount = 0;
    double rowSum = 0;

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



    doubleptr *a =
        new doubleptr[n];

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

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3.1lf ", a[i][j]);
        }
        printf("\n");
    }

    if (negColCount > posRowCount) {
        printf("Column with negative element greater than row with positive sum\n");
    } else if (posRowCount > negColCount) {
        printf("Column with negative element less than row with positive sum\n");
    } else {
        printf("Column with negative element equal with row with positive sum\n");
    }

    for (i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}
