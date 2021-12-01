#include <iostream>
#include <cmath>

int MatrixBSearch(double *array, int low, int rowCount, double unit)
{
    int mid = (low + rowCount) / 2;

    if (low <= rowCount)
    {
        if (unit < array[mid])
        {
            return MatrixBSearch(array, low, mid - 1, unit);
        }
        else if (unit > array[mid])
        {
            return MatrixBSearch(array, mid + 1, rowCount, unit);
        }
        else
        {
            return mid;
        }
    }
    else
    {
        mid = -1;
        return mid;
    }
}

int main()
{
    int rowC;
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

    unitIndx = MatrixBSearch(arr, 0, rowC, unit);

    if (unitIndx != -1)
    {
        printf("Index of %lf is %d\n", unit, unitIndx);
    }
    else
    {
        printf("Not Found\n");
    }

    delete[] arr;

    return 0;
}