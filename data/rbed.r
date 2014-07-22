getwd()

Sys.setenv("PKG_CXXFLAGS"="-std=c++11")
require(Rcpp)
sourceCpp("main.cpp")
x = rbSnpinter("test.bed", 2, 1, 12, 6)
x
x = rbSnpinterInd("test.bed", 2, 1, 12, 6, c(1, 3))
x
y = rbSnpvec("test.bed", 2, c(1, 4, 12), 6)
y
y = rbSnpvecInd("test.bed", 2, c(1, 4, 12), 6, c(1, 3))
y


Rbed = setRefClass("Rbed",
    fields = list(
        bedstem = "character",
        bedpath = "character",
        fampath = "character",
        bimpath = "character",
        nsnp = "numeric",
        nindiv = "numeric",
        nindivApparent = "numeric",
        bytes_snp = "numeric",
        snp = "character"
    ))

Rbed$methods(
    # get the stem of a bed file path, removes the .bed extension at the end
    getstem = function(pathname) {
        gsub("^(.*)\\.bed$", "\\1", pathname)
    }
)

Rbed$methods(
    checkbedsize = function() {
        realsize = file.info(bedpath)$size
        theosize = (nindivApparent * nsnp / 4) + 3
        if (realsize != theosize) {
            stop(sprintf("Size of %s does not match with bim and fam files!", bedpath))
        }
    }
)


## Rbed$methods(
##     bedmat = function() {
##         readbed(bedpath, bytes_snp, nsnp)
##     }
## )

Rbed$methods(
    initialize = function(bed) {
        bedstem <<- getstem(bed)
        bedpath <<- paste(bedstem, "bed", sep=".")
        fampath <<- paste(bedstem, "fam", sep=".")
        bimpath <<- paste(bedstem, "bim", sep=".")
        nsnp <<- R.utils::countLines(bimpath)
        nindiv <<- R.utils::countLines(fampath)
        bytes_snp <<- ceiling(nindiv / 4)
        nindivApparent <<- bytes_snp * 4
        snp <<- read.table(pipe())
        indiv << 
    }
)

rbedobj = Rbed("test.bed")
rbedobj$bedpath
rbedobj$fampath
rbedobj$bimpath
rbedobj$bedstem
rbedobj$nsnp
rbedobj$nindiv
rbedobj$nindivApparent
rbedobj$bytes_snp

