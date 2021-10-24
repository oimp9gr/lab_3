#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a3.h"

#include <vector>

using namespace std;

TEST_CASE("a3: Example", "[task:a3]") {
    Point point;
    Rectangle rectangle;
    SECTION("Example 1") {
        point = {3, 3};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == true);
    }

    SECTION("Example 2") {
        point = {1, 2};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == true);
    }

    SECTION("Example 3") {
        point = {5, 4};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == false);
    }
}

TEST_CASE("a3: Point outside rectangle evaluates to false", "[task:a3]") {
    Point point;
    Rectangle rectangle;
    SECTION("Just outside") {
        point = {0, 4};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == false);
        point = {4, 0};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == false);
        point = {4, 4};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == false);
    }

    SECTION("Negative point coordinates") {
        point = {0, -1};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == false);
        point = {-3, 1};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == false);
        point = {-2, -4};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == false);
    }
}

TEST_CASE("a3: Point inside rectangle evaluates to true", "[task:a3]") {
    Point point;
    Rectangle rectangle;
    SECTION("Just inside") {
        point = {1, 1};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == true);
        point = {2, 2};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == true);
        point = {5, 6};
        rectangle = {7, 8};
        REQUIRE(isInRectangle(point, rectangle) == true);
    }

    SECTION("In corner") {
        point = {0, 3};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == true);
        point = {3, 0};
        rectangle = {3, 3};
        REQUIRE(isInRectangle(point, rectangle) == true);
    }

    SECTION("Just on border") {
        point = {0, 1};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == true);
        point = {3, 1};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == true);
        point = {2, 4};
        rectangle = {3, 4};
        REQUIRE(isInRectangle(point, rectangle) == true);
    }
}

TEST_CASE("a3: Const point and rectangle", "[task:a3]") {
    const Point point{1, 1};
    const Rectangle rectangle{3, 3};
    REQUIRE(isInRectangle(point, rectangle) == true);
}