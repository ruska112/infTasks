#include <fstream>
#include <string>

int main() {
    char name[256];
    int rowCount, columnCount, allElCount;
    int i = 0;
    int j = 0;
    int k = 0;
    double t;

    printf("Enter file name(with .txt): ");
    scanf("%s", name);

    std::ifstream myfile(name);

    if (!myfile) {
        printf("File dosn't open!\n");
    } else {
        do {
            printf("Enter count of rows: ");
            scanf("%d", &rowCount);
        } while (rowCount < 0);

        do {
            printf("Enter count of columns: ");
            scanf("%d", &columnCount);
        } while (columnCount < 0);

        allElCount = rowCount * columnCount;

        double *a = new double[allElCount];

        while ((myfile >> t) && (k < allElCount)) {
            a[k] = t;
            k++;
        }
        
        if (k == allElCount) {
            for (i = 0; i < rowCount; i++) {
                for (j = 0; j < columnCount; j++) {
                    printf("%2.1lf ", a[i * columnCount + j]);
                }
                printf("\n");
            }
        } else {
            printf("Reading error!\n");
        }
    }

    myfile.close();
    return 0;
}
