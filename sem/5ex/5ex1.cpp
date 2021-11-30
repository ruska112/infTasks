#include <iostream>

const double EPS = 1e-4;

int MatrixSeacrh(double *array, int rowCount, int unit, int &res)
{
    int i;
    int result = 1;

    if (array != NULL && rowCount >= 1)
    {
        for (i = 0; i < rowCount; i++)
        {
            if ((unit - array[i]) <= EPS)
            {
                res = i;
            }
        }
        result = 0;
    }

    return result;
}

int main()
{
    int rowC;
    int funcRes;
    int unitIndx;
    double unit;

    do
    {
        system("clear");
        printf("Enter count of rows: ");
        scanf("%d", &rowC);
    } while (rowC <= 0);

    double *arr = new double[rowC];

    for (int i = 0; i < rowC; i++)
    {
        printf("[%d] = ", i);
        scanf("%lf", &arr[i]);
    }

    printf("Enter unit to search: ");
    scanf("%lf", &unit);

    funcRes = MatrixSeacrh(arr, rowC, unit, unitIndx);

    if (funcRes == 0)
    {
        printf("Index of %.2lf is %d\n", unit, unitIndx);
    }
    else
    {
        printf("\nError\n\n");
    }

    return 0;
}