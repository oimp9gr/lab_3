#pragma once

#include "catch.hpp"
#include "util.h"
#include "../solutions/b1.h"

#include <vector>

using namespace std;

TEST_CASE("b1: Example", "[task:b1]") {
    vector<int>v1, v2, expected;
    SECTION("Example 1") {
        v1 = {1, 6, 9};
        v2 = {-3, 4, 12};
        expected = {-3, 1, 4, 6, 9, 12};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);
    }

    SECTION("Example 2") {
        v1 = {-5, 4};
        v2 = {0};
        expected = {-5, 0, 4};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);
    }

    SECTION("Example 3") {
        v1 = {};
        v2 = {};
        expected = {};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);
    }
}