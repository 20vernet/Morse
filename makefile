CXX=g++
CXXFLAGS=-Wall -ggdb -Iinclude
AR=/usr/bin/ar -r 



sources:=sources/
obj := $(sources:.cpp=.o)



all: morse
	@echo $(obj)

snake: main.cpp libmorse.a
	$(CXX) $(CXXFLAGS) $^ -o $@ 

libsnake.a: ${obj}
	${AR} $@ $^



clean: 
	rm morse
	rm libmorse.a
