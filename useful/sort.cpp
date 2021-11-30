#include <iostream>

int arrSorter(double *arr, int rowCount)
{
    int i, j;
    int result = 1;
    double tmpElement; //
    const double EPS = 1e-4;

    if (arr != NULL && rowCount >= 1)
    {
        for (j = 0; j < (rowCount - 1); j++)
        {
            for (i = 0; i < (rowCount - 1); i++)
            {
                if ((arr[i] - arr[i + 1]) > EPS)
                {
                    tmpElement = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmpElement;
                }
            }
        }

        result = 0;
    }

    return result;
}

int main()
{
    int rowCount;
    do
    {
        scanf("%d", &rowCount);
    } while (rowCount <= 0);

    double *arr = new double[rowCount];

    for (int i = 0; i < rowCount; i++)
    {
        scanf("%lf", &arr[i]);
    }

    int funcRes = arrSorter(arr, rowCount);

    if (funcRes == 0)
    {
        for (int i = 0; i < rowCount; i++)
        {
            printf("%.2lf ", arr[i]);
        }
    }
    else
    {
        printf("ERROR\n\n");
    }

    return 0;
}