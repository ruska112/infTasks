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
        double *a = new double[allElCount];

        while ((myfile >> t) && (k < allElCount))
        {
            a[k] = t;
            k++;
        }

        if (k == allElCount)
        {
            for (i = 0; i < rowCount; i++)
            {
                for (j = 0; j < columnCount; j++)
                {
                    printf("%2.1lf ", a[i * columnCount + j]);
                }
                printf("\n");
            }
        }
        else if (k < allElCount)
        {
            printf("\nFewer elements\n");
        }
        else
        {
            printf("\nReading error!\n");
        }
    }

    myfile.close();
    return 0;
}
