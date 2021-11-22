#include <fstream>
#include <string>

int main()
{
    char name[127];
    int rowCount, columnCount, allElCount;
    int i = 0;
    int j = 0;
    int k = 0;
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
        myfile >> columnCount;

        allElCount = rowCount * columnCount;

        double **a = new double *[rowCount];

        for (i = 0; i < rowCount; i++)
        {
            a[i] = new double[columnCount];
        }

        if (a != NULL)
        {
            for (i = 0; (i < rowCount) && ok; i++)
            {
                for (j = 0; (j < columnCount) && ok; j++)
                {
                    ok = bool(myfile >> t);
                    a[i][j] = t;
                    k++;
                }
            }

            if (ok)
            {
                if (k == allElCount)
                {
                    for (i = 0; i < rowCount; i++)
                    {
                        for (j = 0; j < columnCount; j++)
                        {
                            printf("%2.1lf ", a[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if (k < allElCount)
                {
                    printf("\nFewer elements\n");
                }

                for (i = 0; i < rowCount; i++)
                {
                    delete[] a[i];
                }

                delete[] a;
            }
            else
            {
                printf("\nReading error!\n");

                for (i = 0; i < rowCount; i++)
                {
                    delete[] a[i];
                }

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
