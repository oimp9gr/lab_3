#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a8.h"

using namespace std;

TEST_CASE("a8: Example", "[task:a8]") {
    vector<vector<int>> grid;
    SECTION("Example 1") {
        grid = {{1, 3, 2}, {9, 7, 8}, {4, 5, 6}};
        REQUIRE(IsCorrectSudokuSquare(grid) == true);
    }

    SECTION("Example 2") {
        grid = {{1, 1, 3}, {6, 5, 4}, {8, 7, 9}};
        REQUIRE(IsCorrectSudokuSquare(grid) == false);
    }

    SECTION("Example 3") {
        grid = {{0, 1, 2}, {6, 4, 5}, {9, 8, 7}};
        REQUIRE(IsCorrectSudokuSquare(grid) == false);
    }
}

TEST_CASE("a8: Repeating numbers inside grid", "[task:a8]") {
    vector<vector<int>> grid;
    grid = {{8, 7, 2}, {5, 6, 1}, {3, 7, 4}};
    REQUIRE(IsCorrectSudokuSquare(grid) == false);
    grid = {{4, 3, 5}, {8, 1, 3}, {9, 5, 7}};
    REQUIRE(IsCorrectSudokuSquare(grid) == false);
}

TEST_CASE("a8: Incorrect numbers", "[task:a8]") {
    vector<vector<int>> grid;
    grid = {{8, 12, 2}, {5, 6, 1}, {3, 7, 4}};
    REQUIRE(IsCorrectSudokuSquare(grid) == false);
    grid = {{4, 3, 5}, {8, 1, 153}, {9, 5, 7}};
    REQUIRE(IsCorrectSudokuSquare(grid) == false);
}

TEST_CASE("a8: Incorrect and repeating numbers", "[task:a8]") {
    vector<vector<int>> grid;
    grid = {{8, 12, 2}, {5, 6, 1}, {1, 7, 4}};
    REQUIRE(IsCorrectSudokuSquare(grid) == false);
    grid = {{4, 3, 5}, {8, 1, 153}, {9, 5, 3}};
    REQUIRE(IsCorrectSudokuSquare(grid) == false);
}

TEST_CASE("a8: Correct sudoku", "[task:a8]") {
    vector<vector<int>> grid;
    grid = {{4, 3, 5}, {8, 1, 2}, {9, 6, 7}};
    REQUIRE(IsCorrectSudokuSquare(grid) == true);
    grid = {{6, 5, 9}, {4, 3, 8}, {2, 1, 7}};
    REQUIRE(IsCorrectSudokuSquare(grid) == true);
    grid = {{8, 9, 2}, {5, 6, 1}, {3, 7, 4}};
    REQUIRE(IsCorrectSudokuSquare(grid) == true);
}

TEST_CASE("a8: Const sudoku square", "[task:a8]") {
    const vector<vector<int>> grid{{4, 3, 5}, {8, 1, 2}, {9, 6, 7}};
    REQUIRE(IsCorrectSudokuSquare(grid) == true);
}