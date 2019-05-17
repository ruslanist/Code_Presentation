#ifndef MYSTRING_H
#define MYSTRING_H
#include <stdio.h>

class myString {
public:

    class strProxy {
    public:
        strProxy(myString& strProx, size_t iter);
        strProxy& operator= (const strProxy& objStr);
        strProxy& operator= (char c_val);
        operator char () const;

    private:
        myString& proxyObj;
        size_t index_forProx;
    };

    myString(const char *strVal = "");
    myString(const myString& objStr);
    myString& operator=(const myString& objStr);
    const strProxy operator [](size_t index_of_str) const;
    strProxy operator [](size_t index);
    const char* c_str();
    size_t length() const;
    ~myString();
    friend class strProxy;

private:
    struct strvalCount {

        size_t objCount;
        char *valData;

        strvalCount(const char *strVal);
        ~strvalCount();
    };

    strvalCount *Pvalue;
};

#endif // MYSTRING_H
