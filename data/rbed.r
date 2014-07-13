getwd()

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
    getstem = function(pathname) {
        gsub("(.*?)(\\.[^./]+)+", "\\1", pathname)
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


Rbed$methods(
    bedmat = function() {
        readbed(bedpath, bytes_snp, nsnp)
    }
)

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
        snp <<- "0"
    }
)

rbedobj = Rbed("test")
rbedobj$bedmat()

Sys.setenv("PKG_CXXFLAGS"="-std=c++11")
require(Rcpp)
sourceCpp("main.cpp")
x = readbed("test.bed", 2, 12)
x
as.hexmode(x)
testvec1()
testvec2()
vecvec()
