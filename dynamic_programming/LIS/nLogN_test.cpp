#include "catch.hpp"

#include "nLogN.h"

using Catch::Matchers::Equals;

TEST_CASE("1 2 1 4", "[LIS]") {
    vector<int> v{1, 2, 1, 4};
    REQUIRE(setLISLength(v) == 3);
    REQUIRE(bsLISLength(v) == 3);
    vector<int> lis{1, 2, 4};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("1 2 3 3 4", "[LIS]") {
    vector<int> v{1, 2, 3, 3, 4};
    REQUIRE(setLISLength(v) == 4);
    REQUIRE(bsLISLength(v) == 4);
    vector<int> lis{1, 2, 3, 4};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("1", "[LIS]") {
    vector<int> v{1};
    REQUIRE(setLISLength(v) == 1);
    REQUIRE(bsLISLength(v) == 1);
    vector<int> lis{1};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("-1 1", "[LIS]") {
    vector<int> v{-1, 1};
    REQUIRE(setLISLength(v) == 2);
    REQUIRE(bsLISLength(v) == 2);
    vector<int> lis{-1, 1};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("empty", "[LIS]") {
    vector<int> v{};
    REQUIRE(setLISLength(v) == 0);
    REQUIRE(bsLISLength(v) == 0);
    vector<int> lis{};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15", "[LIS]") {
    vector<int> v{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    REQUIRE(setLISLength(v) == 6);
    REQUIRE(bsLISLength(v) == 6);
    vector<int> lis{0, 2, 6, 9, 11, 15};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("1 -1 0", "[LIS]") {
    vector<int> v{1, -1, 0};
    REQUIRE(setLISLength(v) == 2);
    REQUIRE(bsLISLength(v) == 2);
    vector<int> lis{-1, 0};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("1 6 5 4 3 2 7", "[LIS]") {
    vector<int> v{1, 6, 5, 4, 3, 2, 7};
    REQUIRE(setLISLength(v) == 3);
    REQUIRE(bsLISLength(v) == 3);
    vector<int> lis{1, 2, 7};
    REQUIRE_THAT(LIS(v), Equals(lis));
}

TEST_CASE("3 4 1 2 3", "[LIS]") {
    vector<int> v{3, 4, 1, 2, 3};
    REQUIRE(setLISLength(v) == 3);
    REQUIRE(bsLISLength(v) == 3);
    vector<int> lis{1, 2, 3};
    REQUIRE_THAT(LIS(v), Equals(lis));
}