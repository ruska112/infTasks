#include <iostream>

class Table
{
private:
    int rowCount;
    int colCount;
    double **Arr;

public:
    int ArrCreator()
    {
        int result = 1;

        do
        {
            printf("Enter row count: ");
            scanf("%d", &rowCount);
        } while (rowCount < 0);
        do
        {
            printf("Enter column count: ");
            scanf("%d", &colCount);
        } while (colCount < 0);

        if (rowCount > 0 && colCount > 0)
        {
            Arr = new double *[rowCount];
            for (int i = 0; i < rowCount; i++)
                Arr[i] = new double[colCount];
            int i, j;
            for (i = 0; i < rowCount; i++)
            {
                for (j = 0; j < colCount; j++)
                {
                    printf("[%d][%d] = ", i, j);
                    scanf("%lf", &Arr[i][j]);
                }
            }
            if (Arr != NULL)
                result = 0;
        }
        return result;
    }

    void ArrDestructure()
    {
        for (int i = 0; i < rowCount; i++)
            delete[] Arr[i];
        delete[] Arr;
    }

    void ArrPrintf()
    {
        int i, j;

        for (i = 0; i < rowCount; i++)
        {
            for (j = 0; j < colCount; j++)
                printf("%3.1lf ", Arr[i][j]);
            printf("\n");
        }
    }
};

int main()
{

    Table myArr;

    myArr.ArrCreator();

    myArr.ArrPrintf();

    myArr.ArrDestructure();
    return 0;
}
