#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include "../solutions/b4.h"

using namespace std;

TEST_CASE("b4: Example", "[task:b4]") {
    size_t size;
    vector<vector<int>> expected;
    SECTION("Example 1") {
        size = 1;
        expected = {{1}};
        REQUIRE(PascalTriangle(size) == expected);
    }

    SECTION("Example 2") {
        size = 5;
        expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
        REQUIRE(PascalTriangle(size) == expected);
    }
}

TEST_CASE("b4: All Pascal's triangles up to size of 10 and 36", "[task:b4]") {
    size_t size;
    vector<vector<int>> expected;
    SECTION("size of 2") {
        size = 2;
        expected = {{1}, {1, 1}};
        REQUIRE(PascalTriangle(size) == expected);
    }

    SECTION("size of 3") {
        size = 3;
        expected = {{1}, {1, 1}, {1, 2, 1}};
        REQUIRE(PascalTriangle(size) == expected);
    }

    SECTION("size of 4") {
        size = 4;
        expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}};
        REQUIRE(PascalTriangle(size) == expected);
    }

    SECTION("size of 5") {
        size = 5;
        expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
        REQUIRE(PascalTriangle(size) == expected);
    }

    SECTION("size of 6") {
        size = 6;
        expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}};
        REQUIRE(PascalTriangle(size) == expected);
    }

    SECTION("size of 7") {
        size = 7;
        expected =
            {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}, {1, 6, 15, 20, 15, 6, 1}};
        REQUIRE(
            PascalTriangle(size) == expected);
    }

    SECTION("size of 8") {
        size = 8;
        expected =
            {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}, {1, 6, 15, 20, 15, 6, 1},
                {1, 7, 21, 35, 35, 21, 7, 1}};
        REQUIRE(PascalTriangle(size)
                    == expected);
    }

    SECTION("size of 9") {
        size = 9;
        expected =
            {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}, {1, 6, 15, 20, 15, 6, 1},
                {1, 7, 21, 35, 35, 21, 7, 1}, {1, 8, 28, 56, 70, 56, 28, 8, 1}};
        REQUIRE(PascalTriangle(size)
                    == expected);
    }

    SECTION("size of 10") {
        size = 10;
        expected =
            {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}, {1, 6, 15, 20, 15, 6, 1},
                {1, 7, 21, 35, 35, 21, 7, 1}, {1, 8, 28, 56, 70, 56, 28, 8, 1}, {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}};
        REQUIRE(PascalTriangle(size)
                    == expected);
    }
}