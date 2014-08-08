Rbed$methods(
    initialize = function(bedstem) {
        bedstem <<- bedstem
        bedpath <<- paste(bedstem, "bed", sep=".")
        fampath <<- paste(bedstem, "fam", sep=".")
        bimpath <<- paste(bedstem, "bim", sep=".")
        nsnp <<- R.utils::countLines(bimpath)
        nindiv <<- R.utils::countLines(fampath)
        bytes_snp <<- ceiling(nindiv / 4)
        nindivApparent <<- bytes_snp * 4
        snp <<- readcols(bimpath, 2)[[1]];
    }
)
