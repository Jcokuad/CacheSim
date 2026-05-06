#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <cctype>
#include <iomanip>

// helper functions 

// computes log2 of nums for block offset and set index fields
static int log2num(int x) {
    int n = 0;
    while ((1 << n) < x) {
        n++;
    }
    return n;
}

// skips past whitespaces between tokens for parsing each line of the trace file
static size_t skipBlanks(const std::string& str, size_t pos) {
    while (pos < str.size() && std::isspace(static_cast<unsigned char>(str[pos]))) {
        pos++;
    }
    return pos;
}

static std::string readTokan(const std::string& str, size_t pos) {
    size_t ind = pos;
    while (ind < str.size() && !std::isspace(static_cast<unsigned char>(str[ind]))) {
        ind++;
    }
    
    std::string token = str.substr(pos, ind - 1);
    ind = pos;
    return token;
}

static std::string lowerCase(std::string word) {
    for (char& c : word) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return word;
}

// Cache

struct Block { // Represents one cache line
    uint32_t tag;
    bool dirty;
};

struct Set {std}