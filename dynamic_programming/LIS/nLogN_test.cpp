#include "catch.hpp"

#include "./nLogN.h"

TEST_CASE("1 2 1 4", "[LIS]") {
    vector<int> v{1, 2, 1, 4};
    REQUIRE(LISLength(v) == 3);
}

TEST_CASE("1 2 3 3 4", "[LIS]") {
    vector<int> v{1, 2, 3, 3, 4};
    REQUIRE(LISLength(v) == 4);
}

TEST_CASE("1", "[LIS]") {
    vector<int> v{1};
    REQUIRE(LISLength(v) == 1);
}

TEST_CASE("-1 1", "[LIS]") {
    vector<int> v{-1, 1};
    REQUIRE(LISLength(v) == 2);
}

TEST_CASE("empty", "[LIS]") {
    vector<int> v{};
    REQUIRE(LISLength(v) == 0);
}

TEST_CASE("{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}", "[LIS]"){
    vector<int> v{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    REQUIRE(LISLength(v) == 6);
}