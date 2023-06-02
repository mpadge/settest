#include "test.h"

TestSet Set_function ()
{
    TestSet test_set;

    test_set.insert (TestStruct (0.0, 0.0));

    return test_set;
}

//' rcpp_test
//'
//' @noRd
// [[Rcpp::export]]
Rcpp::IntegerVector rcpp_test ()
{
    TestSet test_set = Set_function ();

    return 0L;
}
