# Test R package compilation with >= C++17

CRAN is now completely C++11 compliant, so demands removal of all `CXX_STD`
statements for C++11. This then leaves the standard dependent on the local
system. This repo demonstrates one issue when local systems are >= C++17, which
fail to compile with use of `std::set`. The typical compile error looks
something like this:
```
test.cpp:7:21:   required from here
/usr/include/c++/11/bits/stl_tree.h:770:15: error: static assertion failed: comparison object must be invocable as const
  770 |               is_invocable_v<const _Compare&, const _Key&, const _Key&>,
        |               ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/11/bits/stl_tree.h:770:15: note: ‘std::is_invocable_v<const by_a&, const TestStruct&, const TestStruct&>’ evaluates to false
make: *** [/opt/R/4.3.0/lib/R/etc/Makeconf:200: test.o] Error 1
ERROR: compilation failed for package ‘settest’
```

The solution requires explicitly specifying the set comparison operator as `const`, so changing from
``` cpp
bool operator () (const TestStruct& lhs, const TestStruct& rhs) { ... }
```
to
``` cpp
bool operator () (const TestStruct& lhs, const TestStruct& rhs) const { ... }
```
