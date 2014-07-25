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
