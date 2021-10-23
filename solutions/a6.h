#pragma once

#include <vector>

using namespace std;

struct Product {
    string name;
    double cost;
};

struct Shop {
    vector<Product> shelf_1;
    vector<Product> shelf_2;
    vector<Product> shelf_3;

    double calculateMeanCost();
};

void AddProductToShop(Shop &shop, const Product &product) {
    if (shop.shelf_1.size() < shop.shelf_2.size() && shop.shelf_1.size() < shop.shelf_3.size()) {
        shop.shelf_1.push_back(product);
    } else if (shop.shelf_2.size() < shop.shelf_3.size()) {
        shop.shelf_2.push_back(product);
    } else {
        shop.shelf_3.push_back(product);
    }
}

double Shop::calculateMeanCost() {
    size_t n = shelf_1.size() + shelf_2.size() + shelf_3.size();
    double general_cost = 0;
    for (const auto &pr: shelf_1) {
        general_cost += pr.cost;
    }
    for (const auto &pr: shelf_2) {
        general_cost += pr.cost;
    }
    for (const auto &pr: shelf_3) {
        general_cost += pr.cost;
    }
    return general_cost / n;
}