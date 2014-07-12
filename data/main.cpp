#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "RcppArmadillo.h"
#include "gencodes.h"

// via the depends attribute we tell Rcpp to create hooks for
// RcppArmadillo so that the build process will know what to do
//
// [[Rcpp::depends(RcppArmadillo)]]


using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
arma::imat readbed(std::string bedfn, int bytes_snp, int nsnp_toread) {
	FILE* file_in;
	unsigned char* buffer = 0;
	file_in = fopen(bedfn.c_str(), "rb");
	if(! file_in) {
		throw "Failed to open file.";
	}

	int bytes_read = bytes_snp * nsnp_toread;
	buffer = (unsigned char *)malloc(bytes_read);
	if (!buffer) {
		fclose(file_in);
		fprintf(stderr, "Memory error!");
		throw "Failed to open memory buffer";
	}
	fseeko(file_in, 3, SEEK_SET);
	size_t fread_ret = fread(buffer, bytes_read, 1, file_in);
	if(! fread_ret) {
		throw "Failed to read into buffer!";
	}

	std::vector<int> bed_int_vec;
	bed_int_vec.reserve(sizeof(int) * 4 * bytes_read);
	// for(unsigned char i : buffer) {
	for(int i=0; i<bytes_read; i++) {
		bed_int_vec.insert(bed_int_vec.end(), gencodes[buffer[i]].begin(), gencodes[buffer[i]].end());
	}
	arma::imat bed_int(&bed_int_vec.front(), 4 * bytes_read, 1, false, true);

	free(buffer);
	return bed_int;
}

// [[Rcpp::export]]
void testvec1() {
	std::vector<double> y;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	
	arma::mat x(&y.front(), 3, 1);
	x.print();
}

// [[Rcpp::export]]
void testvec2() {
	std::vector<double> y;
	vector<double> y1 {1, 2};
	vector<double> y2 {1, 3};
	vector<double> y3 {1, 4};
	y.reserve(y1.size() * 3);
	y.insert(y.end(), y1.begin(), y1.end());
	y.insert(y.end(), y2.begin(), y2.end());
	y.insert(y.end(), y3.begin(), y3.end());
	
	arma::mat x(&y.front(), 6, 1);
	x.print();
}

// [[Rcpp::export]]
void vecvec() {
	const std::vector< std::vector<int> > y {
		std::vector<int> {1, 2},
		std::vector<int> {3, 4},
		std::vector<int> {5, 6}
	};
	for(std::vector<int> i : y) {
		for(int j : i) {
			Rcout << j << "\t";
		}
		Rcout << "\n";
	}
}
