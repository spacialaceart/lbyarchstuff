// c calls asm

// functional scalar simd registrrs
// functional scalar simd floating-point instructions

//  input: matrix rows, singlr float matrix values

// number
// row of values

#include <stdio.h>

extern int asmcompute(double vi, double vf, double t); // asm function

int main()
{
  int n;
  double vi, vf, t;
  int result;

  scanf("%d", &n); // read  number of rows

  for (int i = 0; i < n; i++)
  {
    scanf("%lf,%lf,%lf", &vi, &vf, &t);
    result = asmcompute(vi, vf, t);
    printf("%d\n", result);
  }

  return 0;
}
