#include "catch.hpp"

#include "bit.cpp"

TEST_CASE("even query ft", "[FenwickTree]") {
    vector<int> v{1, 2, 3, 4};
    FenwickTree tree(v);
    REQUIRE(tree.query(0) == 1);
    REQUIRE(tree.query(1) == 3);
    REQUIRE(tree.query(2) == 6);
    REQUIRE(tree.query(3) == 10);
}

TEST_CASE("odd query ft", "[FenwickTree]") {
    vector<int> v{1, 2, 3, 4, 5};
    FenwickTree tree(v);
    REQUIRE(tree.query(0) == 1);
    REQUIRE(tree.query(1) == 3);
    REQUIRE(tree.query(2) == 6);
    REQUIRE(tree.query(3) == 10);
    REQUIRE(tree.query(4) == 15);
}

TEST_CASE("point update ft", "[FenwickTree]") {
    vector<int> v{1, 2, 3, 4, 5};
    FenwickTree tree(v);
    tree.update(1, 5);
    REQUIRE(tree.query(1) == 8);
    REQUIRE(tree.query(2) == 11);
    tree.update(2, 1);
    REQUIRE(tree.query(3) == 16);
    REQUIRE(tree.query(2) == 12);
    REQUIRE(tree.query(4) == 21);
}