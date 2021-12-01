#include <iostream>
#include <cmath>

const double EPS = 1e-8;

int MatrixSearch(double *array, int rowCount, double unit, int &res)
{
    int result = 1;
    int low = 0;
    int high = rowCount;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (unit < array[mid])
        {
            high = mid - 1;
        }
        else if (unit > array[mid])
        {
            low = mid + 1;
        }
        else if (fabs(unit - array[mid]) < EPS)
        {
            res = mid;
            result = 0;
            break;
        }
        }
    return result;
}

int main()
{
    int rowC;
    int unitIndx;
    int funcRes;
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

    funcRes = MatrixSearch(arr, rowC, unit, unitIndx);

    if (funcRes == 0)
    {
        printf("Index of %lf is %d\n", unit, unitIndx);
    }
    else if (funcRes == 2)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Error\n");
    }

    delete[] arr;

    return 0;
}