#include "catch.hpp"

#include "nLog2n.h"

using Catch::Matchers::Equals;

TEST_CASE("banana", "[SuffixArray]") {
    vector<int> v{1, 0, 13, 0, 13, 0};
    vector<int> ans{5, 3, 1, 0, 4, 2};
    REQUIRE_THAT(buildSuffixArray(v), Equals(ans));
}

TEST_CASE("yabbadabbado", "[SuffixArray]") {
    vector<int> v{24, 0, 1, 1, 0, 3, 0, 1, 1, 0, 3, 14};
    vector<int> ans{1, 6, 4, 9, 3, 8, 2, 7, 5, 10, 11, 0};
    REQUIRE_THAT(buildSuffixArray(v), Equals(ans));
}