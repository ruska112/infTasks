#include <iostream>

int GCD(int a, int b, int &res) {
  if (a < 0) {
    a = -a;
  }

  if (b < 0) {
    b = -b;
  }

  while ((a != 0) && (b != 0)) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }

  res = a + b;

  return 0;
}

int main() {
  int a, b;
  int NOD = 0;

  printf("Enter a: ");
  scanf("%d", &a);

  printf("Enter b: ");
  scanf("%d", &b);

  int funcRes = GCD(a, b, NOD);

  printf("GCD %d and %d = %d\n", a, b, NOD);

  return 0;
}
