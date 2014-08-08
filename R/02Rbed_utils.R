Rbed$methods(
    checkbedsize = function() {
        realsize = file.info(bedpath)$size
        theosize = (nindivApparent * nsnp / 4) + 3
        if (realsize != theosize) {
            stop(sprintf("Size of %s does not match with bim and fam files!", bedpath))
        }
    }
)
