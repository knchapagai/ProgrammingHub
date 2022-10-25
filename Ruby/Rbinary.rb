convert_to_binary <- function(decnum) {
if(decnum > 1) {
convert_to_binary(as.integer(decnum/2))
}
cat(decnum %% 2)
}
convert_to_binary(52)
