#include <cstdio>
#include <cmath>

int MainFunc(double **array, int lines, int columns, double &res)
{
    /*  Функция обрабатывает массив вещественных чисел-
     *      среди сумм элементов столбцов
     *      находит максимальный
     *
     *  Входные параметры:
     *      array - матрица
     *          (размеры которой lines & columns)
     *      lines - кол-во строк
     *      columns - кол-во столбцов
     *
     *  Выходной параметр:
     *      res - максимальная сумма
     *          элементов столбцов
     *          (передаётся по ссылке)
     *
     *  Программа возвращает:
     *      0 - при успешной работе
     *      1 - при возникновени ошибок
     */
    int result = 1;
    double maxMin = -1e20;
    double tmpElement;
    if (lines > 0 && columns > 0)
    {
        int i, j;
        for (i = 0; i < columns; i++)
        {
            tmpElement = 0;
            for (j = 0; j < lines; j++)
                tmpElement += array[j][i];

            if (tmpElement > maxMin)
            {
                maxMin = tmpElement;
            }
        }

        res = maxMin;
        result = 0;
    }

    return result;
}

int main()
{
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
        printf("\nChoose option:\n");
        printf("Create table:\n");
        printf("    1 - Create the table using rand;\n");
        printf("    2 - Create your hands;\n");
        printf("    3 - Create the table from file;\n");
        printf("4 - Process table;\n");
        printf("5 - Show table;\n");
        printf("6 - Show result;\n");
        printf("Exit:\n");
        printf("    7 - Exit with saving in file;\n");
        printf("    8 - Exit without saving.\n");
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
                    ok = fscanf(readFile, "%i", &columns);
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
                                ok = fscanf(readFile, "%lf", &t);
                                if (ok == 1)
                                {
                                    arr[i][j] = t;
                                }
                            }
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
                funcRes = MainFunc(arr, rows, columns, maxSumRow);

                if (funcRes == 0)
                {
                    printf("\nTable has been processed\n");
                    myBool = 2;
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
        else if (actFU == 5)
        {
            if (myBool == 1)
            {
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < columns; j++)
                        printf(" %4.2lf ", arr[i][j]);
                    printf("\n");
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
                if (funcRes == 0)
                {
                    printf("\nMAX: %4.2lf\n", maxSumRow);
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
        else if (actFU == 7)
        {
            printf("Enter file name(with .txt): ");
            scanf("%s", name);

            FILE *writeFile;
            writeFile = fopen(name, "w");

            fprintf(writeFile, "%d ", rows);
            fprintf(writeFile, "%d ", columns);
            fprintf(writeFile, "\n");

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < columns; j++)
                {
                    fprintf(writeFile, "%.3lf ", arr[i][j]);
                }
                delete[] arr[i];
                fprintf(writeFile, "\n");
            }
            fprintf(writeFile, "\nMAX:%.3lf", maxSumRow);
            fclose(writeFile);
            delete[] arr;
            mainLoop = false;
        }
        else if (actFU == 8)
        {
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
