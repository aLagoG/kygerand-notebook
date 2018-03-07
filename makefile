CXX=g++
CPPFLAGS=-std=c++11 -I$(shell pwd)
SRC=$(shell find . -name "*.cpp")

kygerand: $(SRC:%.cpp=%.o)
	$(CXX) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $^

test: kygerand
	./kygerand

clean:
	rm -f kygerand $(shell find . -name "*.o")