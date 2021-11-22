#include <fstream>

int main()
{
    std::srand(time(0));

    char name[127];
    int allElCount;
    int k = 0;
    double t;
    int min, max;

    printf("Enter file name(with .txt): ");
    scanf("%s", name);

    std::ofstream myfile;
    myfile.open(name);

    if (!myfile)
    {
        printf("File dosn't open!\n");
    }
    else
    {
        do
        {
            printf("Enter count of rows: ");
            scanf("%d", &allElCount);
        } while (allElCount < 0);

        allElCount -= 1;

        printf("Enter min: ");
        scanf("%d", &min);

        printf("Enter mix: ");
        scanf("%d", &max);

        t = (double)(((rand() % (100 * max)) + (50 * min))) * 0.01;

        while ((myfile << t << " ") && (k < allElCount))
        {
            t = (double)(((rand() % (100 * max)) + (50 * min))) * 0.01;
            k++;
        }

        if (k == allElCount)
        {
            printf("\nOk\n");
        }
        else
        {
            printf("Reading error!\n");
        }
    }

    myfile.close();
    return 0;
}
