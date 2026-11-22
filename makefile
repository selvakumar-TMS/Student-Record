out:main.o Allfunction.o
	cc main.c Allfunction.c -o out
main.o:main.c
	cc -c main.c
Allfunction.o:Allfunction.c
	cc -c Allfunction.c
