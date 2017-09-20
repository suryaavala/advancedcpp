all: findMax isNumber addAndPrint

findMax: findMax.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findMax findMax.cpp
	
isNumber: isNumber.cpp numlimits.hpp
	g++ -std=c++11 -Wall -Werror -O2 -o isNumber isNumber.cpp

addAndPrint: addAndPrint.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o addAndPrint addAndPrint.cpp

clean:
	rm findMax isNumber addAndPrint
