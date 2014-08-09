require(devtools)
Sys.setenv("PKG_CXXFLAGS"="-std=c++11")

load_all("~/workspace/rbed")
require(rbed)
toydir = system.file("data", package="rbed")
setwd(toydir)
rbedobj = Rbed("test")
rbedobj$bedpath
rbedobj$fampath
rbedobj$bimpath
rbedobj$bedstem
rbedobj$nsnp
rbedobj$nindiv
rbedobj$nindivApparent
rbedobj$bytes_snp
rbedobj$snp

x = rbedobj$bedmat.full()
x
x = rbedobj$bedmat.snpinter(1, 3)
x
x = rbedobj$bedmat.snpinter.ind(1, 3, c(2, 6))
x

x = rbedobj$bedmat.full()
x
x = rbedobj$bedmat.snpvec(c(1, 3, 12))
x
x = rbedobj$bedmat.snpvec.ind(c(1, 3, 12), c(1, 2, 6))
x

plinkoutfie = "~/Desktop/RS123_1kg.assoc.linear"
x = readplinkoutr(plinkoutfie, c("CHR", "SNP", "BP", "TEST", "P"))
