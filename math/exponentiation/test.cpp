#include "catch.hpp"

#include "binary.h"
#include "modular.h"

typedef unsigned int ui;

TEST_CASE("b^0", "[exponentiation]") {
    ui e = 0;
    int r = 1;
    REQUIRE(pow(1, e) == r);
    REQUIRE(pow(2, e) == r);
    REQUIRE(pow(5, e) == r);
    REQUIRE(pow(0, e) == r);
    REQUIRE(pow(-1, e) == r);
    REQUIRE(pow(-2, e) == r);
    REQUIRE(pow(-5, e) == r);
    int m = 10;
    REQUIRE(pow(1, e, m) == r);
    REQUIRE(pow(2, e, m) == r);
    REQUIRE(pow(5, e, m) == r);
    REQUIRE(pow(0, e, m) == r);
    REQUIRE(pow(-1, e, m) == r);
    REQUIRE(pow(-2, e, m) == r);
    REQUIRE(pow(-5, e, m) == r);
}

TEST_CASE("b^1", "[exponentiation]") {
    ui e = 1;
    int b = 1;
    int m = 10;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
    b = 2;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
    b = 5;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
    b = 0;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
    b = -1;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
    b = -2;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
    b = -5;
    REQUIRE(pow(b, e) == b);
    REQUIRE(pow(b, e, m) == b);
}

TEST_CASE("b^e", "[exponentiation]") {
    REQUIRE(pow(9, 4) == 6561);
    REQUIRE(pow(18, 4) == 104976);
    REQUIRE(pow(7, 4) == 2401);
    REQUIRE(pow(18, 5) == 1889568);
    REQUIRE(pow(4, 6) == 4096);
}

TEST_CASE("(b^e) mod m", "[exponentiation]") {
    REQUIRE(pow(14, 17, 39854) == 9626);
    REQUIRE(pow(14, 17, 43668) == 42824);
    REQUIRE(pow(10, 13, 18568) == 1880);
    REQUIRE(pow(10, 13, 17758) == 3676);
    REQUIRE(pow(6, 16, 27315) == 17991);
    REQUIRE(pow(6, 16, 23629) == 1951);
    REQUIRE(pow(18, 14, 30380) == 27764);
    REQUIRE(pow(18, 14, 11927) == 9280);
    REQUIRE(pow(6, 17, 26400) == 15936);
    REQUIRE(pow(6, 17, 36855) == 7776);
}