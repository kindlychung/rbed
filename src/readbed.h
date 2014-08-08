#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "gencodes.h"
#include "countlines.h"
#include "fileExists.h"
#include "armaheader.h"

using namespace Rcpp;
using namespace std;

arma::imat readbed(std::string bedfn,
				   unsigned int bytes_snp,
				   arma::Col<unsigned int> snp_vec,
				   unsigned int nindiv);

arma::imat readbed(std::string bedfn,
				   unsigned int bytes_snp,
				   arma::Col<unsigned int> snp_vec,
				   unsigned int nindiv,
				   arma::Col<unsigned int> indiv_vec);

arma::imat readbed(
				   std::string bedfn,
				   unsigned int bytes_snp,
				   unsigned int snp_start,
				   unsigned int snp_end,
				   unsigned int nindiv);

arma::imat readbed(std::string bedfn,
				   unsigned int bytes_snp,
				   unsigned int snp_start,
				   unsigned int snp_end,
				   unsigned int nindiv,
				   arma::Col<unsigned int> indiv_vec);


arma::imat rbSnpvec(std::string bedfn,
				   unsigned int bytes_snp,
				   arma::Col<unsigned int> snp_vec,
				   unsigned int nindiv);

arma::imat rbSnpvecInd(std::string bedfn,
				       unsigned int bytes_snp,
				       arma::Col<unsigned int> snp_vec,
					   unsigned int nindiv,
					   arma::Col<unsigned int> indiv_vec
					   );

arma::imat rbSnpinter(std::string bedfn,
					  unsigned int bytes_snp,
					  unsigned int snp_start,
					  unsigned int snp_end,
					  unsigned int nindiv
					  );

arma::imat rbSnpinterInd(std::string bedfn,
					     unsigned int bytes_snp,
					     unsigned int snp_start,
					     unsigned int snp_end,
						 unsigned int nindiv,
						 arma::Col<unsigned int> indiv_vec
					  );

