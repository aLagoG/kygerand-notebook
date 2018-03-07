# kygerand-notebook
Kygerand's ACM ICPC notebook repo

## Test Suite
We are using [Catch2](https://github.com/catchorg/Catch2).

Each source file should have a corresponding test file.
If there is only one source file inside a directory the test file should be named **test.cpp**. If there are more source files, each one should have a corresponding **_test.cpp** i.e. **vector_test.cpp**

## Makefile
The main executable is called kygerand, it is a Catch2 generated executable and thus has a bunch of useful command line options. Use `--help` to get more information.

- To compile everything use: `make`
- To run the test suite use: `make test`
- To clean the repo of executables and object files use: `make clean`
