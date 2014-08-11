# Requirements

* git
* R packages:
    * ggplot2
    * Rcpp
    * RcppArmadillo
    * devtools

# Installation

    require(devtools)
    Sys.setenv("PKG_CXXFLAGS"="-std=c++11")
    install_github("rbed", username="kindlychung")

# Changes

* a minor fix for accomodating r command to changes in a c++ function

# To do
