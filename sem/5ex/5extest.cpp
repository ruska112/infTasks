#include <cstdio>
#include <cmath>

int MatrixSort(double *arr, int rowCount)
{
    int i, j;
    int result = 1;
    double tmpElement;
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

int MainFunc(int &res, double *array, int low, int rowCount, int unit)
{
    int result = 1;

    if (array != NULL && rowCount >= 1)
    {
        res = MatrixBSearch(array, low, rowCount, unit);
        result = 0;
    }

    return result;
}

int main()
{
    int min_el, max_el, funcRes, rows;
    bool mainLoop = true;

    int i;

    int unitIndx;

    int myBool = 0;

    double *arr;

    double unit;

    int actFU;

    bool ok = true;

    char name[127];

    double t;

    // Main Menu
    do
    {
        printf("\nChoose option:\n");
        printf("Create table:\n");
        printf("    1 - Create the table using rand;\n");
        printf("    2 - Create your hands;\n");
        printf("    3 - Create the table from file;\n");
        printf("4 - Sort table;\n");
        printf("5 - Process table;\n");
        printf("6 - Show table;\n");
        printf("7 - Show result;\n");
        printf("Exit:\n");
        printf("    8 - Exit with saving in file;\n");
        printf("    9 - Exit without saving.\n");
        scanf("%d", &actFU);

        if (actFU == 1)
        {
            do
            {
                printf("Enter count of rows: ");
                scanf("%d", &rows);
            } while (rows <= 0);

            arr = new double[rows];

            if (arr != NULL)
            {
                printf("Enter int min: ");
                scanf("%d", &min_el);

                printf("Enter int max: ");
                scanf("%d", &max_el);

                for (i = 0; i < rows; i++)
                    arr[i] = (double)(((rand() % (100 * max_el)) + (50 * min_el))) * 0.01;

                myBool = 1;
            }
            else
            {
                printf("Error\n");
            }
        }
        else if (actFU == 2)
        {
            do
            {
                printf("Enter count of rows: ");
                scanf("%d", &rows);
            } while (rows <= 0);

            arr = new double[rows];

            if (arr != NULL)
            {
                for (i = 0; i < rows; i++)
                {
                    printf("[%d]: ", i);
                    scanf("%lf", &arr[i]);
                }
                myBool = 1;
            }
            else
            {
                printf("\nERROR\n");
            }
        }
        else if (actFU == 3)
        {
            printf("Enter file name(with .txt): ");
            scanf("%s", name);

            FILE *readFile;
            readFile = fopen(name, "r");

            if (readFile)
            {
                ok = fscanf(readFile, "%i", &rows);
                if (ok && rows >= 1)
                {

                    for (i = 0; (i < rows) && ok; i++)
                    {

                        ok = fscanf(readFile, "%lf", &t);
                        if (ok == 1)
                        {
                            arr[i] = t;
                        }

                        myBool = 1;
                    }
                }
                fclose(readFile);
            }
            else
            {
                printf("File dosn't open\n");
            }
        }
        else if (actFU == 4)
        {
            if (myBool == 1)
            {
                funcRes = MatrixSort(arr, rows);
                myBool = 2;
            }
            else
            {
                printf("\nYou haven't sort a table\n");
            }
        }
        else if (actFU == 5)
        {
            if (myBool == 2)
            {
                printf("Enter unit to search: ");
                scanf("%lf", &unit);
                funcRes = MainFunc(unitIndx, arr, 0, rows, unit);

                if (funcRes == 0)
                {
                    printf("\nTable has been processed\n");
                    myBool = 3;
                }
                else
                {
                    printf("\nError\n");
                }
            }
            else
            {
                printf("\nYou haven't created a table\n");
            }
        }
        else if (actFU == 6)
        {
            if (myBool == 2)
            {
                for (i = 0; i < rows; i++)
                {

                    printf(" %4.2lf ", arr[i]);
                }
            }
            else
            {
                printf("\nYou haven't created a table\n");
            }
        }
        else if (actFU == 7)
        {
            if (myBool == 3)
            {
                if (funcRes == 0)
                {
                    printf("\nIndex of element: %d\n", unitIndx);
                }
                else
                {
                    printf("\nError\n");
                }
            }
            else
            {
                printf("\nYou haven't process a table\n");
            }
        }
        else if (actFU == 8)
        {
            printf("Enter file name(with .txt): ");
            scanf("%s", name);

            FILE *writeFile;
            writeFile = fopen(name, "w");

            fprintf(writeFile, "%d ", rows);
            fprintf(writeFile, "\n");

            for (i = 0; i < rows; i++)
            {
                fprintf(writeFile, "%.3lf ", arr[i]);
            }
            fprintf(writeFile, "\n");
            fprintf(writeFile, "\nIndex of matrix:%d", unitIndx);
            fclose(writeFile);
            delete[] arr;
            mainLoop = false;
        }
        else if (actFU == 9)
        {
            delete[] arr;
            mainLoop = false;
        }
        else
        {
            printf("ERROR");
        }
    } while (mainLoop);

    return 0;
}
