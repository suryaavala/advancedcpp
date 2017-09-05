all: smallIntTest safeArrayTest StringPtr SumPos findInt findDouble findIfUsingFunction findIfLamda findIfFunctionObject findIfBind findIfFunctionPointer GT6 GTX lessThan bind oldBind findIfTemplatedFunctionObject lamdaArguments lamdaCaptures biggiesFO

smallIntTest: smallIntTest.o SmallInt.o
	g++ smallIntTest.o SmallInt.o -o smallIntTest

smallIntTest.o: SmallInt.h smallIntTest.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c smallIntTest.cpp

SmallInt.o: SmallInt.h SmallInt.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c SmallInt.cpp
	
safeArrayTest: safeArrayTest.o SafeArray.o
	g++ safeArrayTest.o SafeArray.o -o safeArrayTest

safeArrayTest.o: SafeArray.h safeArrayTest.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c safeArrayTest.cpp

SafeArray.o: SafeArray.h SafeArray.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c SafeArray.cpp
	
Clock.o: Clock.h Clock.cpp
	g++ -std=c++11 -Wall -Werror -O2 -c Clock.cpp
	
StringPtr: StringPtr.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o StringPtr StringPtr.cpp
	
SumPos: SumPos.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o SumPos SumPos.cpp
	
findInt: findInt.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findInt findInt.cpp
	
findDouble: findDouble.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findDouble findDouble.cpp
	
findIfFunctionObject: findIfFunctionObject.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findIfFunctionObject findIfFunctionObject.cpp

findIfBind: findIfBind.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findIfBind findIfBind.cpp
	
findIfLamda: findIfLamda.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findIfLamda findIfLamda.cpp

findIfFunctionPointer: findIfFunctionPointer.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findIfFunctionPointer findIfFunctionPointer.cpp
	
findIfUsingFunction: findIfUsingFunction.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findIfUsingFunction findIfUsingFunction.cpp
	
findIfTemplatedFunctionObject: findIfTemplatedFunctionObject.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o findIfTemplatedFunctionObject findIfTemplatedFunctionObject.cpp
	
GT6: GT6.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o GT6 GT6.cpp

GTX: GTX.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o GTX GTX.cpp
	
lessThan: lessThan.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o lessThan lessThan.cpp

bind: bind.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o bind bind.cpp

lamdaArguments: lamdaArguments.cpp
	g++ -std=c++11 -Wall -Werror -O2 -o lamdaArguments lamdaArguments.cpp

lamdaCaptures: lamdaCaptures.cpp
	g++ -std=c++11 -Wall -O2 -o lamdaCaptures lamdaCaptures.cpp

biggiesFO: biggiesFO.cpp
	g++ -std=c++11 -Wall -O2 -o biggiesFO biggiesFO.cpp

oldBind: oldBind.cpp
	g++ -std=c++11 -Wall -O2 -o oldBind oldBind.cpp

clean:
	rm *o smallIntTest safeArrayTest StringPtr SumPos findInt findDouble findIfUsingFunction findIfFunctionObject findIfBind findIfFunctionPointer GT6 GTX lessThan bind oldBind findIfLamda findIfTemplatedFunctionObject lamdaArguments lamdaCaptures biggiesFO
