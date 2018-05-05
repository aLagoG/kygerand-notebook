CXX=g++
CPPFLAGS=-std=c++11 -I$(shell pwd)
COV_FLAGS=$(CPPFLAGS) -fprofile-arcs -ftest-coverage -g -O0
DEBUG_FLAGS=$(CPPFLAGS) -g

source_files=$(shell find . -not -name "*test.cpp" -name "*.cpp")
test_files=$(shell find . -name "*test.cpp")
h_files=$(source_files:%.cpp=%.h)

s_obj=$(source_files:%.cpp=%.o)
t_obj=$(test_files:%.cpp=%.o)

s_cov=$(source_files:%.cpp=%.co)
t_cov=$(test_files:%.cpp=%.co)

s_dbg=$(source_files:%.cpp=%.do)
t_dbg=$(test_files:%.cpp=%.do)

all: build build_coverage build_debug

build: $(h_files) $(s_obj) $(t_obj)
	$(CXX) $(CPPFLAGS) -o kygerand $(s_obj) $(t_obj)

build_coverage: $(h_files) $(s_cov) $(t_cov)
	$(CXX) $(COV_FLAGS) -o coverage $(s_cov) $(t_cov)

build_debug: $(h_files) $(s_dbg) $(t_dbg)
	$(CXX) $(DEBUG_FLAGS) -o debug $(s_dbg) $(t_dbg)

headers: $(h_files)

%.h: %.cpp
	./generate_header.py $^

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $^

%.do: %.cpp
	$(CXX) $(DEBUG_FLAGS) -c -o $@ $^

%.co: %.cpp
	$(CXX) $(COV_FLAGS) -c -o $@ $^

test: build
	./kygerand

debug_test: build_debug
	gdb ./kygerand

run_coverage: build_coverage
	./coverage

report_coverage: run_coverage
	gcovr -r . --html --html-details -o code_coverage.html --gcov-exclude "#" --gcov-exclude ".*test" --gcov-exclude ".*catch\.hpp"

coverage: report_coverage
	rm -f *.gcov

clean: clean_coverage clean_debug
	rm -f kygerand $(shell find . -name "*.o" -or -name "*.h")

clean_coverage: clean_coverage_data
	rm -f coverage $(shell find . -name "*.co" -or -name "*.gcno" -or -name "*.gcov")

clean_coverage_data:
	rm -f code_coverage*.html $(shell find . -name "*.gcda")

clean_debug:
	rm -f debug $(shell find . -name "*.do")