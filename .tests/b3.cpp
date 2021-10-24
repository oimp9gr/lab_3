#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include "../solutions/b3.h"

using namespace std;

TEST_CASE("b3: Example", "[task:b3]") {
    int64_t number;
    SECTION("Example 1") {
        number = 2718;
        REQUIRE(MultiplicativePersistence(number) == 2);
    }

    SECTION("Example 2") {
        number = 5;
        REQUIRE(MultiplicativePersistence(number) == false);
    }

    SECTION("Example 3") {
        number = 277777788888899;
        REQUIRE(MultiplicativePersistence(number) == 11);
    }
}

TEST_CASE("b3: All numbers until 10", "[task:b3]") {
    int64_t number;

    SECTION("0") {
        number = 1;
        REQUIRE(MultiplicativePersistence(number) == 0);
    }

    SECTION("1") {
        number = 10;
        REQUIRE(MultiplicativePersistence(number) == 1);
    }

    SECTION("2") {
        number = 25;
        REQUIRE(MultiplicativePersistence(number) == 2);
    }

    SECTION("3") {
        number = 39;
        REQUIRE(MultiplicativePersistence(number) == 3);
    }

    SECTION("4") {
        number = 77;
        REQUIRE(MultiplicativePersistence(number) == 4);
    }

    SECTION("5") {
        number = 679;
        REQUIRE(MultiplicativePersistence(number) == 5);
    }

    SECTION("6") {
        number = 6788;
        REQUIRE(MultiplicativePersistence(number) == 6);
    }

    SECTION("7") {
        number = 68889;
        REQUIRE(MultiplicativePersistence(number) == 7);
    }

    SECTION("8") {
        number = 2677889;
        REQUIRE(MultiplicativePersistence(number) == 8);
    }

    SECTION("9") {
        number = 26888999;
        REQUIRE(MultiplicativePersistence(number) == 9);
    }

    SECTION("10") {
        number = 3778888999;
        REQUIRE(MultiplicativePersistence(number) == 10);
    }
}