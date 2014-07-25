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
        snp <<- bimReadCol(bimpath, 2);
    }
)
