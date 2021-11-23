#include <fstream>

int max(double *arr, int rowC, double &res)
{
    int result = 1;

    if (rowC > 0)
    {
        int i = 0;

        res = arr[i];
        for (i = 1; i < rowC; i++)
        {
            if (res < arr[i])
            {
                res = arr[i];
            }
        }
        result = 0;
    }

    return result;
}

int main()
{
    char name[127];
    int rowCount;
    int i, k;
    double t;
    bool ok = true;

    printf("Enter file name(with .txt): ");
    scanf("%s", name);

    std::ifstream myfile(name);

    if (!myfile)
    {
        printf("File dosn't open!\n");
    }
    else
    {
        myfile >> rowCount;

        double *a = new double[rowCount];

        if (a != NULL)
        {
            for (i = 0; (i < rowCount) && ok; i++)
            {
                ok = bool(myfile >> t);
                a[i] = t;
                k++;
            }

            if (ok)
            {
                if (k == rowCount)
                {
                    for (i = 0; i < rowCount; i++)
                    {

                        printf("%4.2lf ", a[i]);
                    }
                    printf("\n");

                    double MAX;

                    int funcR = max(a, rowCount, MAX);

                    if (funcR == 0)
                    {
                        printf("Max = %4.2lf\n", MAX);
                    }
                    else
                    {
                        printf("FUNCERROR");
                    }
                }
                else if (k < rowCount)
                {
                    printf("\nFewer elements\n");
                }

                delete[] a;
            }
            else
            {
                printf("\nReading error!\n");

                delete[] a;
            }
        }
        else
        {
            printf("\nRAM\n");
        }
    }

    myfile.close();

    return 0;
}