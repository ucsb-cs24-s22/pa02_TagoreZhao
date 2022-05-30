CXX_FLAG = --std=c++11 -g

all: test

runMovies: main.o
	g++ $(CXX_FLAG) -o runMovies main.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

movies.o: movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

test.o: test.cpp
	g++ -c $(CXX_FLAG) test.cpp

clean:
	rm -f test *.o