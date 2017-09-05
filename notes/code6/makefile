all: findMin min-user charPtrNonSpecial charPtrSpecial templateDefaults

findMin: findMin.cpp
	g++ -std=c++11 -Wall -Werror -o findMin findMin.cpp
	
min-user: min.h min-instances.o min-user.o
	g++ -std=c++11 -Wall -Werror -o min-user min-instances.o min-user.o
	
min-instances.o: min-instances.cpp min.h
	g++ -std=c++11 -Wall -Werror -c min-instances.cpp

min-user.o: min-user.cpp min.h
	g++ -std=c++11 -Wall -Werror -c min-user.cpp
	
charPtrNonSpecial : charPtrNonSpecial.cpp
	g++ -std=c++11 -Wall -Werror -o charPtrNonSpecial charPtrNonSpecial.cpp

charPtrSpecial : charPtrSpecial.cpp
	g++ -std=c++11 -Wall -Werror -o charPtrSpecial charPtrSpecial.cpp
	
templateDefaults : templateDefaults.cpp
	g++ -std=c++11 -Wall -Werror -o templateDefaults templateDefaults.cpp
	
clean:
	rm *o findMin min-user charPtrNonSpecial charPtrSpecial templateDefaults
