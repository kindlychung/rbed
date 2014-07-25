#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <algorithm>
#include <fstream> 
#include <boost/algorithm/string.hpp>

#include "RcppArmadillo.h"

// via the depends attribute we tell Rcpp to create hooks for
// RcppArmadillo so that the build process will know what to do
// 
// [[Rcpp::depends(RcppArmadillo)]]


using namespace Rcpp;
using namespace std;

inline size_t countlines(std::string fn);
inline void fileExists (const std::string& name);


// count lines of a file
size_t countlines(std::string fn) {
    std::ifstream in_file(fn);
    size_t nlines =  (size_t) std::count(std::istreambuf_iterator<char>(in_file), std::istreambuf_iterator<char>(), '\n');

    // nlines needs be corrected when the last line is not ended with a newline
    in_file.seekg(-1, in_file.end);
    unsigned char lastchar = in_file.get();
    if(lastchar != '\n') {
        ++nlines;
    }

    return nlines;
}

void fileExists (const std::string& name) {
    if ( access( name.c_str(), F_OK ) == -1 ) {
        throw std::string("File does not exist!");
    }
}
