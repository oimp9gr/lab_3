#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b1.h"

#include <vector>
#include <algorithm>

using namespace std;

TEST_CASE("b1: Example", "[task:b1]") {
    vector<int> v1, v2, expected;
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

TEST_CASE("b1: Negative numbers", "[task:b1]") {
    vector<int> v1, v2, expected;
    v1 = {-9000, -100, -60};
    v2 = {-3000, -12, -4};
    expected = {-9000, -3000, -100, -60, -12, -4};
    REQUIRE(MergeSortedArrays(v1, v2) == expected);
}

TEST_CASE("b1: Const array", "[task:b1]") {
    const vector<int> v1{1, 6, 9}, v2{-3, 4, 12}, expected{-3, 1, 4, 6, 9, 12};
    REQUIRE(MergeSortedArrays(v1, v2) == expected);
}

TEST_CASE("b1: Different sizes of arrays", "[task:b1]") {
    vector<int> v1, v2, expected;
    SECTION("First array is smaller") {
        v1 = {1};
        v2 = {-5, 3, 12, 124};
        expected = {-5, 1, 3, 12, 124};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);

        v1 = {};
        v2 = {-5};
        expected = {-5};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);
    }

    SECTION("Second array is smaller") {
        v1 = {-5, 3, 12, 124};
        v2 = {1};
        expected = {-5, 1, 3, 12, 124};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);
        v1 = {-5};
        v2 = {};
        expected = {-5};
        REQUIRE(MergeSortedArrays(v1, v2) == expected);
    }
}


TEST_CASE("b1: Random numbers + stress test", "[task:b1]") {
    vector<int> v1(3000000), v2(3000000), expected(6000000);
    for (size_t i = 0; i < 3000000; ++i) {
        v1[i] = i * 7;
        v2[i] = i * 13;
    }

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), expected.begin());
    REQUIRE(MergeSortedArrays(v1, v2) == expected);
}