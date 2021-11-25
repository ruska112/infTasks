#include <iostream>

const int maxY = 100;
const int maxX = 100;

int matrix(int array[][maxX], int lines, int columns) {
    /* Подпрограмма заполняет
     *      двумерный статический массив целых чисел
     *      так что каждый элемент массива
     *      равен сумме номеров строки и столбца
     *
     * array[][] входно-выходной параметр - массив,
     *      максимальный размер строки - maxX,
     *      на входе не определённый,
     *      на выходе заполненный
     *
     * Входные параметры:
     * lines - реальное число строк
     * columns - реальное число столбцов
     *
     * Функция возвращает
     *      0 - если массив заполнен
     *      1 - если размеры заданы некорректно
    */

    int result = 0;
    if (lines <= 0 || columns <= 0 || lines > maxY || columns > maxX)
        result = 1;
    else {
        int i, j;
        for (i = 0; i < lines; i++)
            for (j = 0; j < columns; j++)
                array[i][j] = i + j;
    }

    return result;
}

int main() {
    int array[maxY][maxX];
    int m, n, result, i, j;

    do {
        printf("Enter count of lines: ");
        scanf("%d", &m);
        printf("Enter count of columns: ");
        scanf("%d", &n);
    } while (m <= 0 || n <= 0 || m > maxY || n > maxX);

    result = matrix(array, m, n);

    if (result == 1)
        printf("\nERROR\n");
    else {
        for (i = 0; i < m; i++) {
            printf("\n");
            for (j = 0; j < n; j++)
                printf("%4d", array[i][j]);
        }
    }
    return 0;
}