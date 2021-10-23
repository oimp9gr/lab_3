#pragma once

#include "catch.hpp"
#include "util.h"
#include "../solutions/a6.h"

#include <vector>

using namespace std;

TEST_CASE("a6: Example", "[task:a6]") {
    Shop shop;
    Product cow{"cow", 100};
    Product horse{"horse", 150};
    AddProductToShop(shop, cow);
    REQUIRE(shop.calculateMeanCost() == 100.0);
    AddProductToShop(shop, horse);
    REQUIRE(shop.calculateMeanCost() == 125.0);
    size_t min_size = min(min(shop.shelf_1.size(), shop.shelf_2.size()), shop.shelf_3.size());
    size_t max_size = max(max(shop.shelf_1.size(), shop.shelf_2.size()), shop.shelf_3.size());
    REQUIRE((max_size - min_size) <= 1);
}

TEST_CASE("a6: Many additions", "[task:a6]") {
    Shop shop;
    double cost = 0;
    Product product{"random", 100};
    for (size_t i = 1; i < 100; ++i) {
        product.cost = rand() % 1000;
        cost += product.cost;
        AddProductToShop(shop, product);
        REQUIRE(shop.calculateMeanCost() == (cost / i));
        size_t min_size = min(min(shop.shelf_1.size(), shop.shelf_2.size()), shop.shelf_3.size());
        size_t max_size = max(max(shop.shelf_1.size(), shop.shelf_2.size()), shop.shelf_3.size());
        REQUIRE((max_size - min_size) <= 1);
    }
}