# Author: Claudious Nhemwa (NHMCLA003)
#Date 17 May 2020
#Compiling binaries needed for compilation
compile: main.o PCAalgorithm.o
	g++ -o pca main.o PCAalgorithm.o  --std=c++11
main.o: main.cpp
	g++ -c main.cpp
PCAalgorithm.o: PCAalgorithm.cpp
	g++ -c -I ./eigen/  PCAalgorithm.cpp  

#clean remove binary files
clean:
	rm *.o pca

#default run using the default data
run:
	./pca
