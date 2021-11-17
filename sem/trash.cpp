#include <iostream>
const int Maxl = 100;
const int Maxc = 100;
int Foggy(double bruh, int c, int z,int &res);
int main()
{
  int i, j;
  int c, z,result,count=0,res;

  setlocale(0, "");
  do
  {
    scanf_s("%i", &i);
    scanf_s("%i", &j);
  } while ( i > Maxl || j > Maxc || i < 1 || j < 1);
  double arr = new double* [(i + j)*8];
  for (int k = 0; k < (i + j); k++)
  {
    arr[k] = new double[(i + j)*8];
  }
  for (c = 0; c < i; c++)
  {
    printf("\n");
    for ( z = 0; z < j; z++)
      scanf_s("%lf\n", &arr[c][z]);
  }
  result = Foggy(arr, i, j,res);
  if (result == 0)
    printf("Ошибочка");
  for (c = 0; c < i; c++)
  {
    printf("\n");
    for (z = 0; z < j; z++)
      printf(" %lf", arr[c][z]);
  }
  printf("\n%i", res);
}
int Foggy(double **bruh,int c,int z,int &res)
{
  int ded=0;
  int count=0;
  if ( c > Maxl || z > Maxc || c < 1 || z < 1)
    ded = 0;
  if (bruh[c][z] > bruh[c][z + 1])
  {
    count++;
    ded = 1;
  }
  res = count;
  return ded;
}
