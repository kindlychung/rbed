Rbed$methods(
    bedmat.full = function() {
        res = rbSnpinter(bedpath, bytes_snp, 1, nsnp, nindiv)
        res[res == -9] = NA
        colnames(res) = snp
        res
    }
)

Rbed$methods(
    bedmat.snpinter = function(snp_start, snp_end) {
        res = rbSnpinter(bedpath, bytes_snp, snp_start, snp_end, nindiv)
        res[res == -9] = NA
        colnames(res) = snp[snp_start:snp_end]
        res
    }
)

Rbed$methods(
    bedmat.snpinter.ind = function(snp_start, snp_end, indiv_vec) {
        res = rbSnpinterInd(bedpath, bytes_snp, snp_start, snp_end, nindiv, indiv_vec)
        res[res == -9] = NA
        colnames(res) = snp[snp_start:snp_end]
        res
    }
)

Rbed$methods(
    bedmat.snpvec = function(snp_vec) {
        res = rbSnpvec(bedpath, bytes_snp, snp_vec, nindiv)
        res[res == -9] = NA
        colnames(res) = snp[snp_vec]
        res
    }
)

Rbed$methods(
    bedmat.snpvec.ind = function(snp_vec, indiv_vec) {
        res = rbSnpvecInd(bedpath, bytes_snp, snp_vec, nindiv, indiv_vec)
        res[res == -9] = NA
        colnames(res) = snp[snp_vec]
        res
    }
)
