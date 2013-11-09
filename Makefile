CFLAGS=-Wall -g

all: ex1-ex10 ex11-ex20 ex21-ex30

ex21-ex30: ex22-main ex23

ex22-main: ex22.o 

ex11-ex20: ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex17-singleconnection ex18 ex20

ex1-ex10: ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10

clean:
	rm -Rf ex1 ex1.dSYM
	rm -Rf ex3 ex3.dSYM
	rm -Rf ex4 ex4.dSYM
	rm -Rf ex5 ex5.dSYM
	rm -Rf ex6 ex6.dSYM
	rm -Rf ex7 ex7.dSYM
	rm -Rf ex8 ex8.dSYM
	rm -Rf ex9 ex9.dSYM
	rm -Rf ex10 ex10.dSYM
	rm -Rf ex11 ex11.dSYM
	rm -Rf ex12 ex12.dSYM
	rm -Rf ex13 ex13.dSYM
	rm -Rf ex14 ex14.dSYM
	rm -Rf ex15 ex15.dSYM
	rm -Rf ex16 ex16.dSYM
	rm -Rf ex17 ex17.dSYM
	rm -Rf ex17-singleconnection ex17-singleconnection.dSYM
	rm -Rf ex18 ex18.dSYM
	rm -Rf ex20 ex20.dSYM
	rm -Rf ex22-main ex22.o ex22-main.dSYM
	rm -Rf ex23 ex23.dSYM
