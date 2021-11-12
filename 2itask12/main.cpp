#include <iostream>

int const maxLines = 128;
int const maxColumns = 128;

double Rand(int MIN, int MAX) {
    return (double) (((rand() % (10 * MAX)) + (5 * MIN))) * 0.1;
}

void RandArrCreator(double array[][maxColumns], int lines, int columns, int minIJ, int maxIJ) {
    int i, j;

    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
            array[i][j] = Rand(minIJ, maxIJ);
}

void HandArrCreator(double array[][maxColumns], int lines, int columns) {
    int i, j;

    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);
        }
}

int MainFunc(double array[][maxColumns], int lines, int columns, double &res) {
    int result = 1;
    double maxMin = -1e20;
    double tmpElement;
    if (lines > 0 && lines < maxLines && columns > 0 && columns < maxColumns) {
        int i, j;
        for (i = 0; i < lines; i++) {
            tmpElement = 0;
            for (j = 0; j < columns; j++)
                tmpElement += array[j][i];
            if (tmpElement > maxMin) {
                maxMin = tmpElement;
            }
        }

        res = maxMin;
        result = 0;
    }

    return result;
}

int main() {
    std::srand(time(0));
    double arr[maxLines][maxColumns], maxColSum;
    int lin, col, minEl, maxEl;
    int res;
    bool mainLoop = true;

    int myBool = 0;

    // Main Menu
    do {
        int actFU;

        printf("\nChoose the option:\n");
        printf("1 - Create the table;\n");
        printf("2 - Process the table;\n");
        printf("3 - Show the table;\n");
        printf("4 - Show the result;\n");
        printf("5 - Exit.\n\n");
        scanf("%d", &actFU);

        if (actFU == 1) {
            int actArrC;

            printf("Choose the option:\n");
            printf("1 - Create the table using random;\n");
            printf("2 - Process the table using your hands;\n");
            scanf("%d", &actArrC);

            if (actArrC == 1) {
                do {
                    printf("Enter count of lines: ");
                    scanf("%d", &lin);
                } while (lin <= 0 || lin > maxLines);

                do {
                    printf("Enter count of columns: ");
                    scanf("%d", &col);
                } while (col <= 0 || col > maxColumns);

                printf("Enter int min: ");
                scanf("%d", &minEl);

                printf("Enter int max: ");
                scanf("%d", &maxEl);

                RandArrCreator(arr, lin, col, minEl, maxEl);

                myBool = 1;
            } else if (actArrC == 2) {
                do {
                    printf("Enter count of lines: ");
                    scanf("%d", &lin);
                } while (lin <= 0 || lin > maxLines);

                do {
                    printf("Enter count of columns: ");
                    scanf("%d", &col);
                } while (col <= 0 || col > maxColumns);

                HandArrCreator(arr, lin, col);
                myBool = 1;
            } else {
                printf("\nERROR\n");
            }
        } else if (actFU == 2) {
            if (myBool == 1) {
                res = MainFunc(arr, lin, col, maxColSum);

                if (res == 0) {
                    printf("\nTable has been processed\n");
                    myBool = 2;
                } else {
                    printf("\nError\n");
                }
            } else {
                printf("\nYou haven't created a table\n");
            }

        } else if (actFU == 3) {
            if (myBool == 1) {
                int i, j;
                for (i = 0; i < lin; i++) {
                    for (j = 0; j < col; j++)
                        printf(" %4.2lf ", arr[i][j]);
                    printf("\n");
                }
            } else {
                printf("\nYou haven't created a table\n");
            }

        } else if (actFU == 4) {
            if (myBool == 2) {
                if (res == 0) {
                    printf("\nMAX: %4.2lf\n", maxColSum);
                } else {
                    printf("\nError\n");
                }
            } else {
                printf("\nYou haven't process a table\n");
            }

        } else if (actFU == 5) {
            mainLoop = false;
        } else {
            printf("ERROR");
        }
    } while (mainLoop);

    return 0;
}
