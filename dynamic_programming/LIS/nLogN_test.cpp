#include "catch.hpp"

#include "./nLogN.cpp"

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

TEST_CASE("floats", "[LIS]") {
    vector<float> v{1, 2, 1};
    REQUIRE(LISLength(v) == 2);
}