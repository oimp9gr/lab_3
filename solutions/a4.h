#pragma once

#include <string>

using namespace std;

bool IsPrefix(const string& word, const string& prefix) {
    return word.length() >= prefix.length() && word.substr(0, prefix.length()) == prefix;
}