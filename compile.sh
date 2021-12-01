gcc -c sortLib.c
gcc -c testLib.c
gcc -c generatorLib.c

gcc -o main testLib.o sortLib.o generatorLib.o main.c