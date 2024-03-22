main: studentai.o
	g++ -o vector vector.cpp studentai.o -O3 
studentai.o: funkcijos.cpp
	g++ -c funkcijos.cpp -o studentai.o
clean:
	rm *.o vector studentai

