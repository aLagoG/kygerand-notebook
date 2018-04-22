#include "catch.hpp"

#include "segment_tree_array.cpp"
#include "segment_tree_nodes.cpp"

using Catch::Matchers::Equals;

TEST_CASE("even query", "[SegmentTree]") {
    vector<int> v{1, 2, 3, 4};
    NodeSegmentTree n_tree(v);
    REQUIRE(n_tree.query(0, 0) == 1);
    REQUIRE(n_tree.query(0, 1) == 3);
    REQUIRE(n_tree.query(0, 2) == 6);
    REQUIRE(n_tree.query(0, 3) == 10);
    REQUIRE(n_tree.query(1, 3) == 9);
    ArraySegmentTree a_tree(v);
    REQUIRE(a_tree.query(0, 0) == 1);
    REQUIRE(a_tree.query(0, 1) == 3);
    REQUIRE(a_tree.query(0, 2) == 6);
    REQUIRE(a_tree.query(0, 3) == 10);
    REQUIRE(a_tree.query(1, 3) == 9);
}

TEST_CASE("odd query", "[SegmentTree]") {
    vector<int> v{1, 2, 3, 4, 5};
    NodeSegmentTree n_tree(v);
    REQUIRE(n_tree.query(0, 0) == 1);
    REQUIRE(n_tree.query(0, 1) == 3);
    REQUIRE(n_tree.query(0, 2) == 6);
    REQUIRE(n_tree.query(0, 3) == 10);
    REQUIRE(n_tree.query(0, 4) == 15);
    REQUIRE(n_tree.query(1, 3) == 9);
    ArraySegmentTree a_tree(v);
    REQUIRE(a_tree.query(0, 0) == 1);
    REQUIRE(a_tree.query(0, 1) == 3);
    REQUIRE(a_tree.query(0, 2) == 6);
    REQUIRE(a_tree.query(0, 3) == 10);
    REQUIRE(a_tree.query(0, 4) == 15);
    REQUIRE(a_tree.query(1, 3) == 9);
}

TEST_CASE("point update", "[SegmentTree]") {
    vector<int> v{1, 2, 3, 4, 5};
    SECTION("node tree") {
        NodeSegmentTree tree(v);
        tree.update(5, 1);
        REQUIRE(tree.query(0, 1) == 6);
        REQUIRE(tree.query(0, 2) == 9);
        tree.update(1, 2);
        REQUIRE(tree.query(0, 3) == 11);
        REQUIRE(tree.query(0, 2) == 7);
        REQUIRE(tree.query(0, 4) == 16);
    }
    SECTION("array tree") {
        ArraySegmentTree tree(v);
        tree.update(5, 1);
        REQUIRE(tree.query(0, 1) == 6);
        REQUIRE(tree.query(0, 2) == 9);
        tree.update(1, 2);
        REQUIRE(tree.query(0, 3) == 11);
        REQUIRE(tree.query(0, 2) == 7);
        REQUIRE(tree.query(0, 4) == 16);
    }
}

TEST_CASE("range update", "[SegmentTree]") {
    vector<int> v{1, 2, 3, 4, 5};
    SECTION("node tree") {
        NodeSegmentTree tree(v);
        tree.updateRange(1, 3, 5);
        REQUIRE(tree.query(1, 3) == 24);
        REQUIRE(tree.query(0, 2) == 16);
        tree.updateRange(2, 4, -8);
        REQUIRE(tree.query(2, 4) == -2);
        REQUIRE(tree.query(3, 4) == -2);
        REQUIRE(tree.query(0, 4) == 6);
    }
    SECTION("array tree") {
        ArraySegmentTree tree(v);
        tree.updateRange(1, 3, 5);
        REQUIRE(tree.query(1, 3) == 24);
        REQUIRE(tree.query(0, 2) == 16);
        tree.updateRange(2, 4, -8);
        REQUIRE(tree.query(2, 4) == -2);
        REQUIRE(tree.query(3, 4) == -2);
        REQUIRE(tree.query(0, 4) == 6);
    }
}

TEST_CASE("lazy update", "[SegmentTree]") {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SECTION("node tree") {
        NodeSegmentTree tree(v);
        tree.updateRange(1, 8, 5);
        REQUIRE(tree.query(1, 3) == 24);
        REQUIRE(tree.query(5, 6) == 23);
        REQUIRE(tree.query(5, 9) == 60);
        tree.updateRange(3, 7, 8);
        tree.updateRange(2, 6, -8);
        REQUIRE(tree.query(2, 4) == 19);
        REQUIRE(tree.query(3, 9) == 87);
        REQUIRE(tree.query(0, 4) == 27);
    }
    SECTION("array tree") {
        ArraySegmentTree tree(v);
        tree.updateRange(1, 8, 5);
        REQUIRE(tree.query(1, 3) == 24);
        REQUIRE(tree.query(5, 6) == 23);
        REQUIRE(tree.query(5, 9) == 60);
        tree.updateRange(3, 7, 8);
        tree.updateRange(2, 6, -8);
        REQUIRE(tree.query(2, 4) == 19);
        REQUIRE(tree.query(3, 9) == 87);
        REQUIRE(tree.query(0, 4) == 27);
    }
}