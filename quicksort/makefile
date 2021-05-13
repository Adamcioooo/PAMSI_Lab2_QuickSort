#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/quicksort

__start__: ./quicksort
	./quicksort

./quicksort: obj obj/main.o obj/quick.o 
                        
	g++ -Wall -pedantic -std=c++11 -o ./quicksort obj/main.o obj/quick.o 

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/quick.hh 
        
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/quick.o: inc/quick.hh src/quick.cpp
	g++ -c ${CXXFLAGS} -o obj/quick.o src/quick.cpp

clean:
	rm -f obj/*.o ./quicksort