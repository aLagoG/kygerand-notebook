#include "catch.hpp"

#include "nLogN.h"

TEST_CASE("1 2 1 4", "[LIS]") {
    vector<int> v{1, 2, 1, 4};
    REQUIRE(setLISLength(v) == 3);
    REQUIRE(bsLISLength(v) == 3);
}

TEST_CASE("1 2 3 3 4", "[LIS]") {
    vector<int> v{1, 2, 3, 3, 4};
    REQUIRE(setLISLength(v) == 4);
    REQUIRE(bsLISLength(v) == 4);
}

TEST_CASE("1", "[LIS]") {
    vector<int> v{1};
    REQUIRE(setLISLength(v) == 1);
    REQUIRE(bsLISLength(v) == 1);
}

TEST_CASE("-1 1", "[LIS]") {
    vector<int> v{-1, 1};
    REQUIRE(setLISLength(v) == 2);
    REQUIRE(bsLISLength(v) == 2);
}

TEST_CASE("empty", "[LIS]") {
    vector<int> v{};
    REQUIRE(setLISLength(v) == 0);
    REQUIRE(bsLISLength(v) == 0);
}

TEST_CASE("{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}", "[LIS]") {
    vector<int> v{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    REQUIRE(setLISLength(v) == 6);
    REQUIRE(bsLISLength(v) == 6);
}