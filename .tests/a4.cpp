#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a4.h"

#include <string>


TEST_CASE("a4: Example", "[task:a4]") {
    string word, prefix;
    SECTION("Example 1") {
        word = "automobile";
        prefix = "auto";
        REQUIRE(IsPrefix(word, prefix) == true);
    }

    SECTION("Example 2") {
        word = "automobile";
        prefix = "Auto";
        REQUIRE(IsPrefix(word, prefix) == false);
    }

    SECTION("Example 3") {
        word = "Promiscuous girl";
        prefix = "Prom";
        REQUIRE(IsPrefix(word, prefix) == true);
    }
}

TEST_CASE("a4: Word's length less or equal to a prefix's length", "[task:a4]") {
    string word, prefix;
    SECTION("Less") {
        word = "abc";
        prefix = "abcd";
        REQUIRE(IsPrefix(word, prefix) == false);
    }

    SECTION("Less") {
        word = "abcd";
        prefix = "abcd";
        REQUIRE(IsPrefix(word, prefix) == true);

        word = "abcd";
        prefix = "abce";
        REQUIRE(IsPrefix(word, prefix) == false);
    }
}

TEST_CASE("a4: Empty string", "[task:a4]") {
    string word, prefix;
    SECTION("Empty word") {
        word = "";
        prefix = "auto";
        REQUIRE(IsPrefix(word, prefix) == false);
    }

    SECTION("Empty prefix") {
        word = "automobile";
        prefix = "";
        REQUIRE(IsPrefix(word, prefix) == true);
    }

    SECTION("Both word and prefix are empty") {
        word = "";
        prefix = "";
        REQUIRE(IsPrefix(word, prefix) == true);
    }
}

TEST_CASE("a4: With spaces", "[task:a4]") {
    string word, prefix;
    SECTION("A prefix") {
        word = "word1   word2    word3";
        prefix = "word1   word2";
        REQUIRE(IsPrefix(word, prefix) == true);
    }

    SECTION("Not a prefix") {
        word = "word1   word2    word3";
        prefix = "word1    word2";
        REQUIRE(IsPrefix(word, prefix) == false);
    }

    SECTION("Only spaces") {
        word = "\t";
        prefix = "    ";
        REQUIRE(IsPrefix(word, prefix) == false);
        word = "\n";
        prefix = "    ";
        REQUIRE(IsPrefix(word, prefix) == false);
        word = "       ";
        prefix = "    ";
        REQUIRE(IsPrefix(word, prefix) == true);
    }
}

TEST_CASE("a4: Randomly generated string", "[task:a4]") {
    vector<char>alphabet = [] {
        vector<char>result;
        for (size_t i = 0; i < 26; ++i) {
            result.push_back('a' + i);
        }
        result.push_back(' ');
        result.push_back('\t');
        result.push_back('\n');
        result.push_back('!');
        result.push_back(',');
        result.push_back('.');
        return result;
    }();
    string word = GenerateStringFromAlphabet(alphabet, 1000);
    string prefix;

    SECTION("A prefix") {
        prefix = word.substr(0, word.length());
        REQUIRE(IsPrefix(word, prefix) == true);

        prefix = word.substr(0, word.length() / 2);
        REQUIRE(IsPrefix(word, prefix) == true);
    }

    SECTION("Not a prefix") {
        prefix = word.substr(0, word.length() / 2) + "?";
        REQUIRE(IsPrefix(word, prefix) == false);
    }
}

TEST_CASE("a4: Const word and prefix", "[task:a4]") {
    const string word = "automobile", prefix = "auto";
    REQUIRE(IsPrefix(word, prefix) == true);
}