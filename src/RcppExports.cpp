// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// C_gen_init_empty
SEXP C_gen_init_empty(SEXP x);
RcppExport SEXP _generatr_C_gen_init_empty(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(C_gen_init_empty(x));
    return rcpp_result_gen;
END_RCPP
}
// C_add_element
void C_add_element(SEXP ptr, SEXP elem);
RcppExport SEXP _generatr_C_add_element(SEXP ptrSEXP, SEXP elemSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< SEXP >::type elem(elemSEXP);
    C_add_element(ptr, elem);
    return R_NilValue;
END_RCPP
}
// C_gen_init_with_vector
SEXP C_gen_init_with_vector(SEXP x);
RcppExport SEXP _generatr_C_gen_init_with_vector(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(C_gen_init_with_vector(x));
    return rcpp_result_gen;
END_RCPP
}
// C_gen_next
SEXP C_gen_next(SEXP ptr, SEXP gen_type);
RcppExport SEXP _generatr_C_gen_next(SEXP ptrSEXP, SEXP gen_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< SEXP >::type gen_type(gen_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(C_gen_next(ptr, gen_type));
    return rcpp_result_gen;
END_RCPP
}
// C_gen_current
SEXP C_gen_current(SEXP ptr, SEXP gen_type);
RcppExport SEXP _generatr_C_gen_current(SEXP ptrSEXP, SEXP gen_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< SEXP >::type gen_type(gen_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(C_gen_current(ptr, gen_type));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_generatr_C_gen_init_empty", (DL_FUNC) &_generatr_C_gen_init_empty, 1},
    {"_generatr_C_add_element", (DL_FUNC) &_generatr_C_add_element, 2},
    {"_generatr_C_gen_init_with_vector", (DL_FUNC) &_generatr_C_gen_init_with_vector, 1},
    {"_generatr_C_gen_next", (DL_FUNC) &_generatr_C_gen_next, 2},
    {"_generatr_C_gen_current", (DL_FUNC) &_generatr_C_gen_current, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_generatr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
