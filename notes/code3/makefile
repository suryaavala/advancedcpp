all: Sales_data_user

Sales_data_user: Sales_data_user.cpp Sales_data.o
	g++ -std=c++11 -Wall -Werror -O2 -o Sales_data_user Sales_data_user.cpp Sales_data.o

Sales_data.o: Sales_data.cpp Sales_data.h
	g++ -std=c++11 -Wall -Werror -O2 -c Sales_data.cpp

clean:
	rm *o Sales_data_user
