#
#   makefile
#   Samuel Lamb
#   cop3330
#   project 2
#   2/8/2019
#




all:      producttest1.x producttest2.x 

producttest1.x: producttest1.o product.o
	g++ -std=c++11 -Wall -Wextra -o producttest1.x product.o producttest1.o

producttest2.x: producttest2.o product.o
	g++ -std=c++11 -Wall -Wextra -o producttest2.x product.o producttest2.o

producttest1.o: product.cpp producttest1.cpp 
	g++ -std=c++11 -Wall -Wextra -c -I. producttest1.cpp 

producttest2.o: product.cpp producttest2.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. producttest2.cpp

product.o:   product.cpp 
	g++ -std=c++11 -Wall -Wextra -c -I. product.cpp
