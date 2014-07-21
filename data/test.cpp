#include <string>
#include <vector>
#include "gencodes.h"

#include "RcppArmadillo.h"

// via the depends attribute we tell Rcpp to create hooks for
// RcppArmadillo so that the build process will know what to do
//
// [[Rcpp::depends(RcppArmadillo)]]


using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
void test_insert_array() {
	std::vector<int> myvec;
	myvec.reserve(4 * sizeof(int));
	int a1[2] = {1, 2};
	int a2[2] = {3, 4};
	myvec.insert(myvec.end(), begin(a1), end(a1));
	myvec.insert(myvec.end(), begin(a2), end(a2));
	for(int i : myvec) {
		Rcout << i << "\n";
	}
}

