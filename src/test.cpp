#include <set>
#include <Rcpp.h>

struct TestStruct
{
    TestStruct (double a): _a (a) {}
    
    double _a;
};

struct by_a
{
    bool operator () (const TestStruct& lhs, const TestStruct& rhs)
    {
        return lhs._a < rhs._a;
    }
}; 

typedef std::set <TestStruct, by_a> TestSet;

TestSet Set_function ()
{
    TestSet test_set;
    test_set.insert (TestStruct (0.0));

    return test_set;
}

//' rcpp_test
//'
//' @noRd
// [[Rcpp::export]]
Rcpp::IntegerVector rcpp_test ()
{
    return 0L;
}
