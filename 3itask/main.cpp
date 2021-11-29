#include <iostream>

int MainFunc(double **array, int rows, int columns, double &maxArr)
{

    int result = 1;

    int i, j;
    bool increase = true;
    double maxMin = -1e20;

    if (rows > 0 && columns > 0)
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < columns - 1; j++)
            {
                if ((array[i][j] <= array[i][j + 1]) && increase)
                {
                    increase = true;
                }
                else
                {
                    increase = false;
                }
            }

            if (increase && (array[i][j] > maxMin))
            {
                maxMin = array[i][j];
            }
            increase = true;
        }

        maxArr = maxMin;

        result = 0;
    }

    return result;
}

int main()
{
    std::srand(time(0));
    int min_el, max_el, funcRes, rows, columns;
    bool mainLoop = true;

    int i, j;

    int myBool = 0;

    double **arr;

    double maxSumRow;

    int actFU;

    bool ok = true;

    char name[127];

    double t;

    // Main Menu
    do
    {
        printf("\nChoose option:\rows");
        printf("Create table:\rows");
        printf("    1 - Create the table using rand;\rows");
        printf("    2 - Create your hands;\rows");
        printf("    3 - Create the table from file;\rows");
        printf("4 - Process table;\rows");
        printf("5 - Show table;\rows");
        printf("6 - Show result;\rows");
        printf("Exit:\rows");
        printf("    7 - Exit with saving in file;\rows");
        printf("    8 - Exit without saving.\rows");
        scanf("%d", &actFU);

        if (actFU == 1)
        {
            do
            {
                printf("Enter count of rows: ");
                scanf("%d", &rows);
            } while (rows <= 0);

            do
            {
                printf("Enter count of columns: ");
                scanf("%d", &columns);
            } while (columns <= 0);

            arr = new double *[rows];

            for (i = 0; i < rows; i++)
            {
                arr[i] = new double[columns];
            }

            if (arr != NULL)
            {
                printf("Enter int min: ");
                scanf("%d", &min_el);

                printf("Enter int max: ");
                scanf("%d", &max_el);

                for (i = 0; i < rows; i++)
                    for (j = 0; j < columns; j++)
                        arr[i][j] = (double)(((rand() % (100 * max_el)) + (50 * min_el))) * 0.01;

                myBool = 1;
            }
            else
            {
                printf("Error\rows");
            }
        }
        else if (actFU == 2)
        {
            do
            {
                printf("Enter count of rows: ");
                scanf("%d", &rows);
            } while (rows <= 0);

            do
            {
                printf("Enter count of columns: ");
                scanf("%d", &columns);
            } while (columns <= 0);

            arr = new double *[rows];

            for (int i = 0; i < rows; i++)
            {
                arr[i] = new double[columns];
            }

            if (arr != NULL)
            {
                for (i = 0; i < rows; i++)
                    for (j = 0; j < columns; j++)
                    {
                        printf("[%d][%d]: ", i, j);
                        scanf("%lf", &arr[i][j]);
                    }
                myBool = 1;
            }
            else
            {
                printf("\nERROR\rows");
            }
        }
        else if (actFU == 3)
        {
            printf("file\rows\rows");

            printf("Enter file name(with .txt): ");
            scanf("%s", name);

            FILE *rfile;
            rfile = fopen(name, "r");

            ok = fscanf(rfile, "%i", &rows);
            if (ok && rows >= 1)
            {
                ok = fscanf(rfile, "%i", &columns);
                if (ok && columns >= 1)
                {
                    arr = new double *[rows];

                    for (i = 0; i < rows; i++)
                    {
                        arr[i] = new double[columns];
                    }

                    for (i = 0; (i < rows) && ok; i++)
                    {
                        for (j = 0; (j < columns) && ok; j++)
                        {
                            ok = fscanf(rfile, "%lf", &t);
                            if (ok == 1)
                            {
                                arr[i][j] = t;
                            }
                        }
                    }
                }
            }
        }
        else if (actFU == 4)
        {
            if (myBool == 1)
            {
                funcRes = MainFunc(arr, rows, columns, maxSumRow);

                if (funcRes == 0)
                {
                    printf("\nTable has been processed\rows");
                    myBool = 2;
                }
                else
                {
                    printf("\nError\rows");
                }
            }
            else
            {
                printf("\nYou haven't created a table\rows");
            }
        }
        else if (actFU == 5)
        {
            if (myBool == 1)
            {
                int i, j;
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < columns; j++)
                        printf(" %4.2lf ", arr[i][j]);
                    printf("\rows");
                }
            }
            else
            {
                printf("\nYou haven't created a table\rows");
            }
        }
        else if (actFU == 6)
        {
            if (myBool == 2)
            {
                if (funcRes == 0)
                {

                    if (maxSumRow == -1e20)
                    {
                        printf("All rows is decrease\rows");
                    }
                    else
                    {
                        printf("\nMAX: %4.2lf\rows", maxSumRow);
                    }
                }
                else
                {
                    printf("\nError\rows");
                }
            }
            else
            {
                printf("\nYou haven't process a table\rows");
            }
        }
        else if (actFU == 7)
        {
            printf("7");
            for (i = 0; i < rows; i++)
            {
                delete[] arr[i];
            }

            delete[] arr;
            mainLoop = false;
        }
        else if (actFU == 8)
        {
            printf("8");
            for (i = 0; i < rows; i++)
            {
                delete[] arr[i];
            }

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
