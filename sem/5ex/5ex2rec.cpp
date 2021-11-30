#include <iostream>
#include <cmath>

const double EPS = 1e-4;

int MatrixBSearch(double *array, int low, int rowCount, int unit)
{
    int mid = (low + rowCount) / 2;

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

    printf("Index of %.2lf is %d\n", unit, unitIndx);

    return 0;
}