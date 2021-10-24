#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b2.h"

#include <string>

using namespace std;

TEST_CASE("b2: Example", "[task:b2]") {
    vector<vector<char>> grid;
    SECTION("Example 1") {
        grid = {
            {'X', 'O', '.'},
            {'.', 'X', 'O'},
            {'.', '.', 'X'}
        };
        REQUIRE(TicTacToeResult(grid) == "X");
    }

    SECTION("Example 2") {
        grid = {
            {'X', 'O', 'X'},
            {'O', 'X', '.'},
            {'X', '.', 'O'}
        };
        REQUIRE(TicTacToeResult(grid) == "X");
    }

    SECTION("Example 3") {
        grid = {
            {'X', 'X', 'O'},
            {'O', 'O', 'X'},
            {'X', 'X', 'O'}
        };
        REQUIRE(TicTacToeResult(grid) == "Tie");
    }
}

TEST_CASE("b2: Test horizontal", "[task:b2]") {
    vector<vector<char>> grid;
    grid = {
        {'X', 'X', '.'},
        {'O', 'X', 'X'},
        {'O', 'O', 'O'}
    };
    REQUIRE(TicTacToeResult(grid) == "O");
    grid = {
        {'X', 'X', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'O'}
    };
    REQUIRE(TicTacToeResult(grid) == "X");
}
TEST_CASE("b2: Test vertical", "[task:b2]") {
    vector<vector<char>> grid;
    grid = {
        {'X', 'X', '.'},
        {'O', 'X', 'X'},
        {'O', 'X', 'O'}
    };
    REQUIRE(TicTacToeResult(grid) == "X");
    grid = {
        {'X', 'X', 'O'},
        {'O', 'X', 'O'},
        {'X', 'O', 'O'}
    };
    REQUIRE(TicTacToeResult(grid) == "O");
}

TEST_CASE("b2: Test tie", "[task:b2]") {
    vector<vector<char>> grid;
    grid = {
        {'X', 'X', '.'},
        {'O', 'O', 'X'},
        {'O', 'X', 'O'}
    };
    REQUIRE(TicTacToeResult(grid) == "Tie");
    grid = {
        {'X', '.', 'O'},
        {'.', '.', '.'},
        {'X', 'O', 'O'}
    };
    REQUIRE(TicTacToeResult(grid) == "Tie");
}

TEST_CASE("b2: Const grid", "[task:b2]") {
    const vector<vector<char>> grid{
        {'X', 'X', '.'},
        {'O', 'O', 'X'},
        {'O', 'X', 'O'}
    };
    REQUIRE_NOTHROW(TicTacToeResult(grid));
}