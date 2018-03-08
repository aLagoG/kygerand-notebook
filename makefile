CXX=g++
CPPFLAGS=-std=c++11 -I$(shell pwd)
COV_FLAGS=$(CPPFLAGS) -fprofile-arcs -ftest-coverage -g

source_files=$(shell find . -not -name "*test.cpp" -name "*.cpp")
test_files=$(shell find . -name "*test.cpp")
s_obj=$(source_files:%.cpp=%.o)
t_obj=$(test_files:%.cpp=%.o)
s_cov=$(source_files:%.cpp=%.co)
t_cov=$(test_files:%.cpp=%.co)
h_files=$(source_files:%.cpp=%.h)

all: build build_coverage

build: $(h_files) $(s_obj) $(t_obj)
	$(CXX) $(CPPFLAGS) -o kygerand $(s_obj) $(t_obj)

build_coverage: $(h_files) $(s_cov) $(t_cov)
	$(CXX) $(COV_FLAGS) -o coverage $(s_cov) $(t_cov)

headers: $(h_files)

%.h: %.cpp
	./generate_header.py $^

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $^

%.co: %.cpp
	$(CXX) $(COV_FLAGS) -c -o $@ $^

test: build
	./kygerand

run_coverage: build_coverage
	./coverage

filter_coverage: run_coverage
	rm -f $(shell find . -name "*test.gcda" -or -name "*test.gcno")

coverage: filter_coverage
	gcovr -r . --html --html-details -o code_coverage.html

clean: clean_coverage
	rm -f kygerand $(shell find . -name "*.o" -or -name "*.h")

clean_coverage:
	rm -f coverage code_coverage*.html $(shell find . -name "*.co" -or -name "*.gcno" -or -name "*.gcda" -or -name "*.gcov")

clean_coverage_data:
	rm -f code_coverage*.html $(shell find . -name "*.gcda")