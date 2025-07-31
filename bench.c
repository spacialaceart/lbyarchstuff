#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int asmcompute(double vi, double vf, double t);

void benchmark(int count)
{
  double vi, vf, t;
  int result;
  clock_t start, end;
  double total_time = 0;

  for (int run = 0; run < 30; run++)
  {
    start = clock();

    for (int i = 0; i < count; i++)
    {
      // Generate random input
      vi = (double)(rand() % 201); // 0–200 km/h
      vf = (double)(rand() % 201);
      t = ((double)(rand() % 90) + 1); // 1–90 seconds

      result = asmcompute(vi, vf, t);
      // optional: verify output, ignore printing
    }

    end = clock();
    total_time += (double)(end - start) / CLOCKS_PER_SEC;
  }

  printf("Size: %d, Avg time over 30 runs: %.6f seconds\n", count, total_time / 30.0);
}

int main()
{
  srand(time(NULL));
  int sizes[] = {10, 100, 1000, 10000};
  int numSizes = sizeof(sizes) / sizeof(sizes[0]);

  for (int i = 0; i < numSizes; i++)
  {
    benchmark(sizes[i]);
  }

  return 0;
}
