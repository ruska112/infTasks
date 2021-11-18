#include <iostream>

int GCD(int a, int b, int &res, int &k, int &l) {
  if (a < 0) {
    a = -a;
  }

  if (b < 0) {
    b = -b;
  }

  while ((a != 0) && (b != 0)) {
    if (a > b) {
      a %= b;
      k++;
    } else {
      b %= a;
      l++;
    }
  }

  res = a + b;

  return 0;
}

int main() {
  int a, b;
  int NOD, k, l;
  k = 0;
  l = 0;

  printf("Enter a: ");
  scanf("%d", &a);

  printf("Enter b: ");
  scanf("%d", &b);

  int funcRes = GCD(a, b, NOD, k, l);
    
  printf("%d %d", k, l);

    double dk = 2 * l / double(a);
    double dl = 2 * k / double(b);

  printf("GCD %d and %d = %d\n", a, b, NOD);

    printf("%lf %lf", dk, dl);

  return 0;
}

