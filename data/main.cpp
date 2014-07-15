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
arma::imat readbed(std::string bedfn, int bytes_snp, int nsnp_toread, int nindiv) {
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

	// expand each byte into 4 genotypes
	std::vector<int> bed_int_vec;
	bed_int_vec.reserve(sizeof(int) * 4 * bytes_read);
	for(int i=0; i<bytes_read; i++) {
		bed_int_vec.insert(bed_int_vec.end(), gencodes[buffer[i]].begin(), gencodes[buffer[i]].end());
	}
	arma::imat bed_int(&bed_int_vec.front(), 4 * bytes_snp, nsnp_toread);
	arma::imat bed_int_strip;
	bed_int_strip = bed_int(arma::span(0, nindiv-1), arma::span::all);


	free(buffer);
	return bed_int_strip;
}



// [[Rcpp::export]]
arma::mat testcols(arma::mat x, arma::Col<unsigned int> idx) {
	arma::mat xsub;
	xsub = x.cols(idx-1);
	return xsub;
}
// [[Rcpp::export]]
arma::mat testrows(arma::mat x, arma::Col<unsigned int> idx) {
	arma::mat xsub;
	xsub = x.rows(idx-1);
	return xsub;
}
// [[Rcpp::export]]
arma::mat testcr(arma::mat x, arma::Col<unsigned int> ridx, arma::Col<unsigned int> cidx) {
	arma::mat xsub;
	xsub = x.submat(ridx-1, cidx-1);
	return xsub;
}
