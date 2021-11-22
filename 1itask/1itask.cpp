#include <iostream>
#include <cmath>
#include <cstring>

int main()
{
    // SETTINGS VARIABLE
    const short ColumnCount = 2;
    const short LineCount = 10;

    const char *argc = "Argument";
    const char *func = "Function";

    // VARIABLE INITIALIZATION
    const float NegativeXBorder = -2.7f;
    const float PositiveXBorder = 2.3f;
    const float NegativePBorder = -3.0f;
    const float PositivePBorder = 3.0f;
    const float TabStep = 0.025f;
    const short AllSigns = 11;
    const short SignsAftDot = 4;
    const short XAllSigns = 6;
    const short XSignsAftDot = 3;

    int PageNum = 1;

    double x = NegativeXBorder;
    double y;
    double p = 0;

    unsigned short argcTab = XAllSigns + 4 - strlen(argc);
    unsigned short funcTab = AllSigns - strlen(func);
    int ColumnLen = XAllSigns + AllSigns + 9;
    int strTab = ColumnLen * ColumnCount / 3;
    double XBorder = PositiveXBorder + 0.5 * TabStep;

    // Main Loops
    do
    {
        system("clear");
        printf("Enter the value of the parameter (from -3 to 3): ");
        scanf("%lf", &p);
    } while ((p < NegativePBorder) || (p > PositivePBorder));

    while (x <= XBorder)
    {
        printf("%*s", strTab, " ");
        printf("Page №%i\n", PageNum);
        printf("%*s", strTab, " ");
        printf("Function value table\n");
        printf("%*s", strTab, " ");
        printf("With the parameter %*.*e\n", XAllSigns, XSignsAftDot, p);

        for (int l = 0; l < ColumnCount; l++)
        {
            for (int i = 0; i < ColumnLen; i++)
            {
                printf("*");
            }
        }
        printf("*\n");

        for (int l = 0; l < ColumnCount; l++)
        {
            printf("*");
            printf("%*s", argcTab, " ");
            printf("%s ", argc);
            printf("*");
            printf("%*s", funcTab, " ");
            printf("%s  ", func);
        }
        printf("*\n");

        for (int l = 0; l < ColumnCount; l++)
        {
            for (int i = 0; i < ColumnLen; i++)
            {
                printf("*");
            }
        }
        printf("*\n");

        for (short j = 0; (j < LineCount) && (x <= XBorder); j++)
        {
            for (short k = 0; k < ColumnCount; k++)
            {
                if (x <= XBorder)
                {
                    printf("*  %*.*lf   ", XAllSigns, XSignsAftDot, x);

                    if (x <= atan(p + x))
                    {
                        y = (pow((1 + x * x * pow(p, 4)), 1 / 5.f)) / (2 * M_PI - x);
                    }
                    else
                    {
                        y = log10(1 + exp(fabs(p * x)));
                    }
                    printf("* %*.*e ", AllSigns, SignsAftDot, y);
                }
                else
                {
                    printf("*   %*s  %s  %*s", XAllSigns, " ", "*", AllSigns, " ");
                }
                x += TabStep;
            }
            printf("*\n");
        }

        for (int l = 0; l < ColumnCount; l++)
        {
            for (int i = 0; i < ColumnLen; i++)
            {
                printf("*");
            }
        }
        printf("*\n");

        //        printf("Press any key to continue...");
        system("echo 'Press ENTER to continue...'; read _");
        printf("\n");
        PageNum++;
    }

    return 0;
}