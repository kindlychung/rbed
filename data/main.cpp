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
arma::imat readbed(std::string bedfn, unsigned int bytes_snp, unsigned int snp_start, unsigned int snp_end, unsigned int nindiv) {
	FILE* file_in;
	unsigned char* buffer = 0;
	file_in = fopen(bedfn.c_str(), "rb");
	if(! file_in) {
		throw "Failed to open file.";
	}

	if(snp_end < snp_start) throw "Make sure that SNP start index <= SNP end index!";
	unsigned int nsnp_toread = snp_end - snp_start + 1;
	unsigned int bytes_read = bytes_snp * nsnp_toread;
	unsigned int bytes_skip = bytes_snp * (snp_start - 1) + 3;
	Rcout << bytes_skip << " bytes are skipped." << "\n";
	buffer = (unsigned char *)malloc(bytes_read);
	if (!buffer) {
		fclose(file_in);
		fprintf(stderr, "Memory error!");
		throw "Failed to open memory buffer";
	}
	fseeko(file_in, bytes_skip, SEEK_SET);
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


