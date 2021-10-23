#pragma once

#include "catch.hpp"
#include "util.h"
#include "../solutions/c2.h"

#include <vector>

using namespace std;

TEST_CASE("c2: Example", "[task:c2]") {
    vector<int> v{7, 2, 3, 4, 15, -4, -4, 10};
    Stats stats = GetStats(v);
    REQUIRE(stats.size == 8);
    REQUIRE(stats.median == 3.5);
    REQUIRE(stats.mode == -4);
    REQUIRE(stats.range == 19);
    REQUIRE(stats.mean == 4.125);
}