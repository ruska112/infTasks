#import <iostream>

const int maxY = 128;
const int maxX = 128;

int ArrCreator(double array[][maxX], int lines, int columns) {
    int res = 0;
    int i, j;

    if (lines <= 0 || columns <= 0 || lines > maxY || columns > maxX)
        res = 1;
    else {
        for (i = 0; i < lines; i++)
            for (j = 0; j < columns; j++) {
                printf("Enter arr[%d][%d]\n", i, j);
                scanf("%lf", &array[i][j]);
            }
    }
    return res;
}

void MatrixRepacker(double array[][maxX], int lines, int columns) {
    int i, j;
    int zeroMatrix[lines];
    int zeroCounter = 0;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            if (array[i][j] == 0) {
                zeroCounter++;
            }
        }
        zeroMatrix[i] += zeroCounter;
    }

    double tmpArr[maxX];

    for (int k = 0; k < lines; k++) {
        if (zeroMatrix[k] > 0)
            for (int l = 0; l < columns; l++) {
                if (array[k][l] < 0)
                    tmpArr[k] += (-array[k][l]);
            }
    }

    double tmpElement = tmpArr[0];

    for (int k = 0; k < lines; ++k) {
        printf("%lf  ", tmpArr[k]);
        if (tmpElement < tmpArr[k])
            tmpElement = tmpArr[k];
    }
}

int main() {
    int lines, columns;
    double myArr[maxY][maxX];
    do {
        printf("Enter lines: ");
        scanf("%d", &lines);
    } while (lines < 1);

    do {
        printf("Enter columns: ");
        scanf("%d", &columns);
    } while (columns < 1);

    int ACRes = ArrCreator(myArr, lines, columns);

    if (ACRes == 1) {
        printf("Error with creating array (check your lines and columns values)");
    } else {
        MatrixRepacker(myArr, lines, columns);
    }

    return 0;
}