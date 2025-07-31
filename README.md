assemble the accel calc program: nasm -f win64 assembly.asm -o accel.obj && gcc x86code.c accel.obj -o accel.exe
accel.exe

![accel](https://github.com/spacialaceart/lbyarchstuff/blob/main/results/run-accel.png)

assemble the benchmark: nasm -f win64 assembly.asm -o assembly.obj && gcc -c bench.c -o bench.obj && gcc bench.obj assembly.obj -o benchmark.exe
benchmark.exe

![benchmark](https://github.com/spacialaceart/lbyarchstuff/blob/main/results/benchmark-results.png)

analysis:
due to the use of SIMD fx in assembly, it had extremely fast computation due to its highly efficient nature on mathematical operations. 
there is also a minimal use of C (just only passing params). if there were more C overhead, it would have been slower as C is a high level programming language.

video:
![u have 2 download it](https://github.com/spacialaceart/lbyarchstuff/blob/main/video%20record/recording.mkv)
