all: recast arrayPrinting autoRange stringContainer map ostreamIterator formatting simpleString manyPeople

recast: recast.o
	g++ recast.o -o recast

recast.o: recast.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c recast.cpp

arrayPrinting: arrayPrinting.o
	g++ arrayPrinting.o -o arrayPrinting

arrayPrinting.o: arrayPrinting.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c arrayPrinting.cpp

autoRange: autoRange.o
	g++ autoRange.o -o autoRange

autoRange.o: autoRange.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c autoRange.cpp

stringContainer: stringContainer.o
	g++ stringContainer.o -o stringContainer

stringContainer.o: stringContainer.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c stringContainer.cpp

map: map.o
	g++ map.o -o map

map.o: map.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c map.cpp
	
ostreamIterator : ostreamIterator.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o ostreamIterator ostreamIterator.cpp
	
formatting: formatting.o
	g++ formatting.o -o formatting

formatting.o: formatting.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c formatting.cpp

simpleString: simpleString.o
	g++ simpleString.o -o simpleString

simpleString.o: simpleString.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c simpleString.cpp

manyPeople: manyPeople.o
	g++ manyPeople.o -o manyPeople

manyPeople.o: manyPeople.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c manyPeople.cpp

clean:
	rm *.o recast arrayPrinting autoRange stringContainer map ostreamIterator formatting simpleString manyPeople
