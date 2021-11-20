#include <iostream>

class List
{
private:
    int rowCount;
    double *Array;

public:
    void ArrConstructor()
    {
        do
        {
            system("clear");
            printf("Enter row count: ");
            scanf("%d", &rowCount);
        } while (rowCount < 0);

        Array = new double[rowCount];

        if (Array == NULL)
            printf("Failed to create array!\n");
    }

    void ArrDestructure()
    {
        if (Array != NULL)
        {
            delete[] Array;
        }
    }

    void ArrFiller()
    {
        int i;
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

                    system("clear");
                    printf("[%d] = ", i);
                    scanf("%lf", &Array[i]);
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
                    Array[i] = (double)(((rand() % (100 * MAX)) + (50 * MIN))) * 0.01;
                }
            }
        }
        else
        {
            printf("\nError!\n");
        }
    }

    void
    ArrPrintf()
    {
        int i;
        if (Array != NULL)
        {
            for (i = 0; i < rowCount; i++)
            {
                printf("%4.2lf ", Array[i]);
            }
            printf("\n");
        }
    }
};

int main()
{
    List myArr;

    myArr.ArrConstructor();
    myArr.ArrFiller();
    myArr.ArrPrintf();
    myArr.ArrDestructure();
    return 0;
}
