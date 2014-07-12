getwd()


Sys.setenv("PKG_CXXFLAGS"="-std=c++11")
require(Rcpp)
sourceCpp("main.cpp")
x = readbed("test.bed", 2, 12)
x
as.hexmode(x)
testvec1()
testvec2()
vecvec()
