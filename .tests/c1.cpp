#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/c1.h"

#include <vector>

using namespace std;

TEST_CASE("c1: Example", "[task:c1]") {
    vector<int> v;
    vector<int> expected;

    SECTION("Example 1") {
        v = {1, 9, 0, -5};
        expected = v;
        MergeSort(v);
        sort(expected.begin(), expected.end());
        REQUIRE(expected == v);
    }

    SECTION("Example 2") {
        v = {};
        expected = v;
        MergeSort(v);
        sort(expected.begin(), expected.end());
        REQUIRE(expected == v);
    }
}

TEST_CASE("c1: Many comparisons to standard sort", "[task:c1]") {
    for (size_t i = 0; i < 100; ++i) {
        vector<int> v(rand() % 10001);
        for (auto &el: v) {
            el = rand() % 100000;
        }
        vector<int> expected(v);
        sort(expected.begin(), expected.end());
        MergeSort(v);
        REQUIRE(v == expected);
    }
}

TEST_CASE("c1: Sort already sorted", "[task:c1]") {
    vector<int> v(10000);
    iota(v.begin(), v.end(), 0);
    auto expected = v;
    MergeSort(v);
    REQUIRE(v == expected);
}