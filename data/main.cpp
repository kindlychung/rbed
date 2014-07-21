#include <string>
#include <vector>
#include <cstdlib>
#include "gencodes.h"

#include "RcppArmadillo.h"

// via the depends attribute we tell Rcpp to create hooks for
// RcppArmadillo so that the build process will know what to do
//
// [[Rcpp::depends(RcppArmadillo)]]

typedef arma::Col<unsigned int> uintvec;

using namespace Rcpp;
using namespace std;

arma::imat readbed(std::string bedfn,
				   unsigned int bytes_snp,
				   uintvec snp_vec,
				   unsigned int nindiv) {
	// open the file handle on .bed file
	FILE* file_in;
	file_in = fopen(bedfn.c_str(), "rb");
	if(! file_in) {
		throw "Failed to open file.";
	}

	unsigned int nsnp_toread = snp_vec.n_elem;
	unsigned int bytes_read = bytes_snp * nsnp_toread;

	uintvec snp_skip_vec = (snp_vec - 1) * bytes_snp + 3;
	uintvec::iterator snp_skip_start = snp_skip_vec.begin();
	uintvec::iterator snp_skip_end = snp_skip_vec.end();

	std::vector<unsigned char> buffer;
	buffer.reserve(bytes_read);
	std::vector<unsigned char> snp_buffer(bytes_snp);

	for(uintvec::iterator offset_i = snp_skip_start; offset_i != snp_skip_end; offset_i++) {
		fseeko(file_in, *offset_i, SEEK_SET);
		size_t fread_ret = fread(&snp_buffer.front(), bytes_snp, 1, file_in);
		if(! fread_ret) {
			throw "Failed to read into buffer!";
		}
		buffer.insert(buffer.end(), snp_buffer.begin(), snp_buffer.end());
	}

	// expand each byte into 4 genotypes (integers in R -- 0, 1, 2)
	std::vector<int> bed_int_vec;
	bed_int_vec.reserve(sizeof(int) * 4 * bytes_read);
	for(int i=0; i<bytes_read; i++) {
		bed_int_vec.insert(bed_int_vec.end(), gencodes[buffer[i]].begin(), gencodes[buffer[i]].end());
	}
	arma::imat bed_int(&bed_int_vec.front(), 4 * bytes_snp, nsnp_toread);
	arma::imat bed_int_strip;
	bed_int_strip = bed_int(arma::span(0, nindiv-1), arma::span::all);

	return bed_int_strip;
}

arma::imat readbed(std::string bedfn,
				   unsigned int bytes_snp,
				   uintvec snp_vec,
				   unsigned int nindiv,
				   uintvec indiv_vec) {
	arma::imat bedmat_snpsel = readbed(bedfn, bytes_snp, snp_vec, nindiv);
	arma::imat bedmat_snpsel_indivsel;
	bedmat_snpsel_indivsel = bedmat_snpsel.rows(indiv_vec - 1);
	return bedmat_snpsel_indivsel;
}

arma::imat readbed(
				   std::string bedfn,
				   unsigned int bytes_snp,
				   unsigned int snp_start,
				   unsigned int snp_end,
				   unsigned int nindiv) {
	FILE* file_in;
	file_in = fopen(bedfn.c_str(), "rb");
	if(! file_in) {
		throw "Failed to open file.";
	}

	if(snp_end < snp_start) throw "Make sure that SNP start index <= SNP end index!";
	unsigned int nsnp_toread = snp_end - snp_start + 1;
	unsigned int bytes_read = bytes_snp * nsnp_toread;
	unsigned int bytes_skip = bytes_snp * (snp_start - 1) + 3;
	std::vector<unsigned char> buffer(bytes_read);
	fseeko(file_in, bytes_skip, SEEK_SET);
	size_t fread_ret = fread(&buffer.front(), bytes_read, 1, file_in);
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

	return bed_int_strip;
}

arma::imat readbed(std::string bedfn,
				   unsigned int bytes_snp,
				   unsigned int snp_start,
				   unsigned int snp_end,
				   unsigned int nindiv,
				   uintvec indiv_vec) {
	arma::imat bedmat_snpsel = readbed(bedfn, bytes_snp, snp_start, snp_end, nindiv);
	arma::imat bedmat_snpsel_indivsel;
	bedmat_snpsel_indivsel = bedmat_snpsel.rows(indiv_vec - 1);
	return bedmat_snpsel_indivsel;
}

// [[Rcpp::export]]
arma::imat rbSnpvec(std::string bedfn,
				   unsigned int bytes_snp,
				   uintvec snp_vec,
				   unsigned int nindiv) {
	return readbed(bedfn, bytes_snp, snp_vec, nindiv);
}

// [[Rcpp::export]]
arma::imat rbSnpvecInd(std::string bedfn,
				       unsigned int bytes_snp,
				       uintvec snp_vec,
					   unsigned int nindiv,
					   uintvec indiv_vec
					   ) {
	return readbed(bedfn, bytes_snp, snp_vec, nindiv, indiv_vec);
}

// [[Rcpp::export]]
arma::imat rbSnpinter(std::string bedfn,
					  unsigned int bytes_snp,
					  unsigned int snp_start,
					  unsigned int snp_end,
					  unsigned int nindiv
					  ) {
	return readbed(bedfn, bytes_snp, snp_start, snp_end, nindiv);
}

// [[Rcpp::export]]
arma::imat rbSnpinterInd(std::string bedfn,
					     unsigned int bytes_snp,
					     unsigned int snp_start,
					     unsigned int snp_end,
						 unsigned int nindiv,
						 uintvec indiv_vec
					  ) {
	return readbed(bedfn, bytes_snp, snp_start, snp_end, nindiv, indiv_vec);
}

