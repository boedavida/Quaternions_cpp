// mytest.h


#ifndef __mytest__
#define __mytest__

#include <cstdio>

#define __mytest_VERSION "1.0"

constexpr const char * __rslt_pass = "pass";
constexpr const char * __rslt_fail = "fail";

class mytest {
    const char *_testDescrp = nullptr;
    
    unsigned long int _passCount = 0;
    unsigned long int _failCount = 0;
    bool _summaryFlag = false;
    
    mytest(mytest & );                   // Disable copy constructor
    mytest operator = (mytest & );       // Disable assignment operator
    mytest(){}                           // Disable default constructor
public:
    mytest( const char * );
    void init ( const char * );
    bool summary ( bool flag ) { return _summaryFlag = flag; }
    bool summary() { return _summaryFlag; }
    unsigned long int passCount() const { return _passCount; }
    unsigned long int failCount() const { return _failCount; }
    static const char * version() { return __mytest_VERSION; }
    void test ( const char * description, const int flag );
    void report() const;
};

#endif /* defined(__mytest__) */
