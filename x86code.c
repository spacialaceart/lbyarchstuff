// c calls asm

// functional scalar simd registrrs
// functional scalar simd floating-point instructions

//  input: matrix rows, single float matrix values

// number
// row of values

#include <stdio.h>

extern int asmcompute(double vi, double vf, double t); // asm function

int main()
{
  int n;
  double vi, vf, t;
  int result;

  printf("Enter number of cars: ");
  scanf("%d", &n); // read number of rows
  
  printf("\nEnter car data (format: initial_velocity(KM/H),final_velocity(KM/H),time(s)):\n");

  for (int i = 0; i < n; i++)
  {
    printf("Car %d: ", i + 1);
    scanf("%lf,%lf,%lf", &vi, &vf, &t);
    result = asmcompute(vi, vf, t);
    printf("  Input: %.1f KM/H -> %.1f KM/H in %.1f s\n", vi, vf, t);
    printf("  Result: %d m/s^2\n\n", result);
  }

  return 0;
}
