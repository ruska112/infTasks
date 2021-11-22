#include <iostream>

double Rand(int MIN, int MAX)
{
    return (double)(((rand() % (10 * MAX)) + (5 * MIN))) * 0.1;
}

void rand_arrc(double **array, int rows, int columns, int minIJ, int maxIJ)
{
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            array[i][j] = Rand(minIJ, maxIJ);
}

void hand_arrc(double **array, int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);
        }
}

int MainFunc(double **array, int rows, int columns, double &maxArr)
{
    /*  Функция обрабатывает массив вещественных чисел-
     *      среди сумм элементов столбцов
     *      находит максимальный
     *
     *  Входные параметры:
     *      array - матрица
     *          (размеры которой rows & columns)
     *      rows - кол-во строк
     *      columns - кол-во столбцов
     *
     *  Выходной параметр:
     *      maxArr - максимальный элемент
     *          в строке упорядоченной
     *          по не убыванию
     *          (передаётся по ссылке)
     *  
     *  Программа возвращает:
     *      0 - при успешной работе
     *      1 - при возникновени ошибок
     */
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
    int min_el, max_el, funcRes, n, m;
    bool mainLoop = true;

    int myBool = 0;

    double **arr;

    double maxSumRow;

    // Main Menu
    do
    {
        int actFU;

        printf("\nChoose option:\n");
        printf("1 - Create table;\n");
        printf("2 - Process table;\n");
        printf("3 - Show table;\n");
        printf("4 - Show result;\n");
        printf("5 - Exit.\n\n");
        scanf("%d", &actFU);

        if (actFU == 1)
        {
            int actArrC;

            printf("Choose the option:\n");
            printf("1 - Create the table using rand;\n");
            printf("2 - Create your hands;\n");
            scanf("%d", &actArrC);

            if (actArrC == 1)
            {
                do
                {
                    printf("Enter count of rows: ");
                    scanf("%d", &n);
                } while (n <= 0);

                do
                {
                    printf("Enter count of columns: ");
                    scanf("%d", &m);
                } while (m <= 0);

                arr = new double *[n];

                for (int i = 0; i < n; i++)
                {
                    arr[i] = new double[m];
                }

                if (arr != NULL)
                {
                    printf("Enter int min: ");
                    scanf("%d", &min_el);

                    printf("Enter int max: ");
                    scanf("%d", &max_el);

                    rand_arrc(arr, n, m, min_el, max_el);

                    myBool = 1;
                }
                else
                {
                    printf("Error\n");
                }
            }
            else if (actArrC == 2)
            {
                do
                {
                    printf("Enter count of rows: ");
                    scanf("%d", &n);
                } while (n <= 0);

                do
                {
                    printf("Enter count of columns: ");
                    scanf("%d", &m);
                } while (m <= 0);

                arr = new double *[n];

                for (int i = 0; i < n; i++)
                {
                    arr[i] = new double[m];
                }

                if (arr != NULL)
                {
                    hand_arrc(arr, n, m);
                    myBool = 1;
                }
                else
                {
                    printf("\nERROR\n");
                }
            }
            else
            {
                printf("\nERROR\n");
            }
        }
        else if (actFU == 2)
        {
            if (myBool == 1)
            {
                funcRes = MainFunc(arr, n, m, maxSumRow);

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
        else if (actFU == 3)
        {
            if (myBool == 1)
            {
                int i, j;
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                        printf(" %4.2lf ", arr[i][j]);
                    printf("\n");
                }
            }
            else
            {
                printf("\nYou haven't created a table\n");
            }
        }
        else if (actFU == 4)
        {
            if (myBool == 2)
            {
                if (funcRes == 0)
                {

                    if (maxSumRow == -1e20)
                    {
                        printf("All rows is decrease\n");
                    }
                    else
                    {
                        printf("\nMAX: %4.2lf\n", maxSumRow);
                    }
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
        else if (actFU == 5)
        {
            mainLoop = false;
        }
        else
        {
            printf("ERROR");
        }
    } while (mainLoop);

    return 0;
}