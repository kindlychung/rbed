/*
 * readcols.h
 *
 *  Created on: Jul 26, 2014
 *      Author: kaiyin
 */

#ifndef READCOLS_H_
#define READCOLS_H_



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "ncols.h"
#include "countlines.h"
//#include <Rcpp.h>

std::vector< std::vector<std::string> > readcols(std::string fn,
		std::vector<unsigned int> colsel, size_t nFirstSkipLines,
		size_t nSkipUnit);


#endif /* READCOLS_H_ */

