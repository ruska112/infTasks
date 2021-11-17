#include <fstream>
#include <iostream>

#include <string>

const int maxL = 128;
const int maxC = 128;

int main()

{
  std::ifstream file("table.txt");
  int ok = 0;
  int lin = 5, col;
  double elmn;
  double arr[maxL][maxC];

  file >> lin;
  if (ok == 0) {
    printf("%d \n", lin);
  } else {
    printf("error");
  }

  file >> col;
  printf("%d \n", col);

  int i, j;

  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++) {
      file >> elmn;
      arr[i][j] = elmn;

      printf("%lf ", arr[i][j]);
    }
    printf("\n");
  }

  file.close();
  return 0;
}
