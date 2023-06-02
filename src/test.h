#pragma once

#include <set>
#include <Rcpp.h>

struct TestStruct
{
    TestStruct (double a, double b): _a (a), _b (b) {}
    
    double _a;
    double _b;

    double geta () const { return _a;   }
    double getb () const { return _b;   }
};

struct by_a
{
    bool operator () (const TestStruct& lhs, const TestStruct& rhs)
    {
        return lhs._a < rhs._a;
    }
}; 

typedef std::set <TestStruct, by_a> TestSet;
