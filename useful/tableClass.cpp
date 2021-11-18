#include <iostream>

class Table {
    private:
        int rowCount;
        int colCount;
        double** Arr;

    public:
        int ArrConstructor() {
            int result = 1;

            do {
                printf("Enter row count: ");
                scanf("%d", &rowCount);
            } while(rowCount < 0);
            do {
                printf("Enter column count: ");
                scanf("%d", &colCount);
            } while(colCount < 0);

            Arr = new double*[rowCount];
            for (int i = 0; i < rowCount; i++)
                Arr[i] = new double[colCount];

            if (Arr != NULL)
                result = 0;

            return result;
        }

        void ArrDestructure() {
           for (int i = 0; i < rowCount; i++)
                delete[] Arr[i];
           delete[] Arr;
        }

        void ArrFiller() {
            int i, j;
            int actFU;
            std::srand(time(0));

            printf("Choise filling method:\n");
            printf("1 - Hand\n");
            printf("2 - Rand\n");
            scanf("%d", &actFU);
            if (actFU == 1) {
                for (i = 0; i < rowCount; i++) {
                    for (j = 0; j < colCount; j++) {
                        printf("[%d][%d] = ", i, j);
                        scanf("%lf", &Arr[i][j]);
                    }
                }
            } else if (actFU == 2) {
                int MIN, MAX;
                printf("Enter min value: ");
                scanf("%d", &MIN);
                printf("Enter max value: ");
                scanf("%d", &MAX);

                for (i = 0; i < rowCount; i++) {
                    for (j = 0; j < colCount; j++) {
                        Arr[i][j] = (double) (((rand() % (10 * MAX)) + (5 * MIN))) * 0.1 ;
                    }
                }

            }

        }

        void ArrPrintf() {
            int i, j;

            for (i = 0; i < rowCount; i++) {
                for (j = 0; j < colCount; j++)
                    printf("%3.1lf ", Arr[i][j]);
                printf("\n");
            }
        }
};

int main() {

    Table myArr;

    myArr.ArrConstructor();
    myArr.ArrFiller();
    myArr.ArrPrintf();

    myArr.ArrDestructure();
    return 0;
}
