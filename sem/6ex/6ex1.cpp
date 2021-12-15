#include <stdio.h>

int linGCD(int x, int y, int *d, int *u, int *v)
{
  int a, b, q, r, u1, v1, u2, v2, result;
  int t;

  a = x;
  b = y;
  u1 = 1;
  v1 = 0;
  u2 = 0;
  v2 = 1;
  result = 1;

  if (a > 0 && b > 0)
  {
    while (b != 0)
    {

      q = a / b;
      r = a % b;
      a = b;
      b = r;

      t = u2;
      u2 = u1 - q * u2;
      u1 = t;

      t = v2;
      v2 = v1 - q * v2;
      v1 = t;
    }

    *d = a;
    *u = u1;
    *v = v1;
    result = 0;
  }
  return result;
}

int main()
{
  int x, y, d, u, v, funcRes;
  printf("Enter a:\n");
  scanf("%d", &x);
  printf("Enter b:\n");
  scanf("%d", &y);

  funcRes = linGCD(x, y, &d, &u, &v);
  if (funcRes == 0)
  {
    printf("GCD = \n%d = (%d)*%d + (%d)*%d\n", d, u, x, v, y);
  }
  else
  {
    printf("Error!");
  }

  return 0;
}
