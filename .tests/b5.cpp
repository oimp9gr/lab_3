#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include "../solutions/b5.h"

using namespace std;

TEST_CASE("b5: Example", "[task:b5]") {
    vector<int> prices;
    SECTION("Example 1") {
        prices = {7, 1, 5, 3, 6, 4};
        REQUIRE(MaxProfit(prices) == 5);
    }

    SECTION("Example 1") {
        prices = {10, 5, 3, 0};
        REQUIRE(MaxProfit(prices) == 0);
    }
}

TEST_CASE("b5: Increasing, decreasing order", "[task:b5]") {
    vector<int> prices;
    SECTION("Increasing") {
        prices = {1, 2, 3, 4, 5, 6, 7};
        REQUIRE(MaxProfit(prices) == 6);
    }

    SECTION("Decreasing") {
        prices = {7, 6, 5, 4, 3, 2, 1};
        REQUIRE(MaxProfit(prices) == 0);
    }

    SECTION("Half increasing") {
        prices = {1, 3, 5, 7, 9, 0, 3, 7, 2, 12};
        REQUIRE(MaxProfit(prices) == 12);
    }

    SECTION("Half decreasing") {
        prices = {9, 7, 6, 5, 4, 3, 2, 1, 3, 7, 2, 0};
        REQUIRE(MaxProfit(prices) == 6);
    }
}

TEST_CASE("b5: Random generated", "[task:b5]") {
    vector<int> prices = {9383,886,2777,6915,7793,8335,5386,492,6649,1421,2362,27,8690,59,7763,3926,540,3426,9172,5736,5211,5368,2567,6429,5782,1530,2862,5123,4067,3135,3929,9802,4022,3058,3069,8167,1393,8456,5011,8042,6229,7373,4421,4919,3784,8537,5198,4324,8315,4370,6413,3526,6091,8980,9956,1873,6862,9170,6996,7281,2305,925,7084,6327,336,6505,846,1729,1313,5857,6124,3895,9582,545,8814,3367,5434,364,4043,3750,1087,6808,7276,7178,5788,3584,5403,2651,2754,2399,9932,5060,9676,3368,7739,12,6226,8586,8094,7539};
    REQUIRE(MaxProfit(prices) == 9929);
}

TEST_CASE("b5: Stress test", "[task:b5]") {
    vector<int> prices(100000);
    ifstream in(".tests/test_b5.txt");
    for (size_t i = 0; i < 100000; ++i) {
        in >> prices[i];
    }
    REQUIRE(MaxProfit(prices) == 99997563);
}