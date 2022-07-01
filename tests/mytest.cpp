// mytest.cpp

#include "mytest.h"

mytest::mytest( const char * testDescrp) {
    init(testDescrp);
}

void mytest::init( const char * testDescrp) {
    _testDescrp = testDescrp;
    _passCount = _failCount = 0;
}

void mytest::test ( const char * description, const int flag ) {
    const char * pf = nullptr;
    if (flag) {
        pf = __rslt_pass;
        ++_passCount;
    } else {
        pf = __rslt_fail;
        ++_failCount;
    }
    if(!_summaryFlag) printf("%s: %s -> %s\n", _testDescrp, description, pf);
}

void mytest::report() const {
    printf("%s: pass: %ld, fail: %ld\n", _testDescrp, passCount(), failCount());
    fflush(stdout);
}
