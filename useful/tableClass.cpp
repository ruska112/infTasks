#include <iostream>

class Table
{
private:
    int rowCount;
    int colCount;
    double **Array;

public:
    void ArrConstructor()
    {
        do
        {
            system("clear");
            printf("Enter row count: ");
            scanf("%d", &rowCount);
        } while (rowCount < 0);

        do
        {
            system("clear");
            printf("Enter column count: ");
            scanf("%d", &colCount);
        } while (colCount < 0);

        Array = new double *[rowCount];
        for (int i = 0; i < rowCount; i++)
            Array[i] = new double[colCount];

        if (Array == NULL)
            printf("Failed to create array!\n");
    }

    void ArrDestructure()
    {
        if (Array != NULL)
        {
            for (int i = 0; i < rowCount; i++)
                delete[] Array[i];
            delete[] Array;
        }
    }

    void ArrFiller()
    {
        int i, j;
        int actFU;
        std::srand(time(0));

        if (Array != NULL)
        {
            system("clear");
            printf("Choise filling method:\n");
            printf("1 - Hand\n");
            printf("2 - Rand\n");
            scanf("%d", &actFU);
            if (actFU == 1)
            {
                for (i = 0; i < rowCount; i++)
                {
                    for (j = 0; j < colCount; j++)
                    {
                        system("clear");
                        printf("[%d][%d] = ", i, j);
                        scanf("%lf", &Array[i][j]);
                    }
                }
            }
            else if (actFU == 2)
            {
                int MIN, MAX;
                printf("Enter min value: ");
                scanf("%d", &MIN);
                printf("Enter max value: ");
                scanf("%d", &MAX);

                for (i = 0; i < rowCount; i++)
                {
                    for (j = 0; j < colCount; j++)
                    {
                        Array[i][j] = (double)(((rand() % (100 * MAX)) + (50 * MIN))) * 0.01;
                    }
                }
            }
        }
        else
        {
            printf("\nError!\n");
        }
    }

    void ArrPrintf()
    {
        int i, j;
        if (Array != NULL)
        {
            for (i = 0; i < rowCount; i++)
            {
                for (j = 0; j < colCount; j++)
                    printf("%4.2lf ", Array[i][j]);
                printf("\n");
            }
        }
    }
};

int main()
{
    Table myArr;

    myArr.ArrConstructor();
    myArr.ArrFiller();
    myArr.ArrPrintf();
    myArr.ArrDestructure();
    return 0;
}
