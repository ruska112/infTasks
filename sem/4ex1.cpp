#include <iostream>

typedef double* doubleptr;

int main() {

    const int maxRow = 128;
    const int maxCol = 128;

    int n, m;
    int i, j;

    bool decrease = true;
    
    int decreaseRowCount = 0;


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
        for (j = 0; j < m && decrease; j++) {
            if ( a[i][j] < a[i][j+1] ) {
                decrease = false;
            }
        }
        if (decrease) {
            decreaseRowCount++;
        }
        decrease = true;
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3.1lf ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n%d\n", decreaseRowCount);
    
    for (i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}
