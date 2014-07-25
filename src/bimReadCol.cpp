#include "bimReadCol.h"


size_t bimNCols(std::string fn) {
    try {
        fileExists(fn);
        std::ifstream in_file(fn);
        std::string tmpline;
        std::getline(in_file, tmpline);
        std::vector<std::string> strs;
        strs = boost::split(strs, tmpline, boost::is_any_of("\t"), boost::token_compress_on);
        return strs.size();
    } catch (const std::string& e) {
        std::cerr << "\n" << e << "\n";
        exit(EXIT_FAILURE);
    }
}

///////////////// export the following to R //////////////////

// [[Rcpp::export]]
CharacterVector bimReadCol(std::string fn, unsigned int ncol_select) {
    try {
        size_t ncols = bimNCols(fn);
		size_t nlines = countlines(fn);
		Rcout << fn << " has " << ncols << " cols.\n";
		Rcout << fn << " has " << nlines << " lines.\n";
        if(ncol_select < 1 or ncol_select > ncols) {
            throw std::string("Your column selection is out of range!");
        }

        std::ifstream in_file(fn);
        CharacterVector colsel(nlines); // holds the column of strings
        std::string tmpword;
		size_t line_counter = 0;
        while (in_file) {
            tmpword = "";
            for(int i=1; i<=ncol_select; i++) {
                in_file >> tmpword;
            }
            if(tmpword != "") {
				colsel[line_counter] = tmpword;
				line_counter++;
            }
            in_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return colsel;

    } catch (const std::string& e) {
        std::cerr << "\n" << e << "\n";
        exit(EXIT_FAILURE);
    }
}
