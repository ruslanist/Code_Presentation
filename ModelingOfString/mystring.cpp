#include "mystring.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <execinfo.h>

using namespace std;

// strvalCount:
myString::strvalCount::strvalCount(const char *strVal) : objCount(1) {

    if(strVal == 0) {

        throw  runtime_error("invalid_argument obj == 0");
    }

    valData = new char[strlen(strVal)+1];

    strcpy(valData, strVal);
}

myString::strvalCount::~strvalCount() {

        delete [] valData;
}

// myString
myString::myString(const char *strVal) : Pvalue(new strvalCount(strVal)) {

}

myString::myString(const myString& objStr) : Pvalue(objStr.Pvalue) {

    ++Pvalue->objCount;
}

myString& myString::operator=(const myString& objStr) {

    if(Pvalue == objStr.Pvalue) {

        return *this;
    }

    if(--Pvalue->objCount == 0) {

        delete  Pvalue;
    }

    Pvalue = objStr.Pvalue;
    ++Pvalue->objCount;
    return *this;
}

const myString::strProxy myString::operator[](size_t index_of_str) const {

    return strProxy(const_cast<myString&>(*this), index_of_str);
}

myString::strProxy myString::operator[](size_t index_of_str) {

    return strProxy(*this, index_of_str);
}

size_t myString::length() const {

    return strlen(this->Pvalue->valData) +1;
}

const char* myString::c_str() {

    return this->Pvalue->valData;
}

myString::~myString() {

    if(--Pvalue->objCount == 0) {

        delete Pvalue;
    }
}

// strProxy
myString::strProxy::strProxy(myString& strProx, size_t iter) : proxyObj(strProx), index_forProx(iter) {

}

myString::strProxy::operator char() const {

    return proxyObj.Pvalue->valData[index_forProx];
}

myString::strProxy& myString::strProxy::operator=(const strProxy &objStr) {

    if(proxyObj.Pvalue->objCount > 1) {

        proxyObj.Pvalue = new strvalCount (proxyObj.Pvalue->valData);
    }

    proxyObj.Pvalue->valData[index_forProx] = objStr.proxyObj.Pvalue->valData[objStr.index_forProx];

    return  *this;
}

myString::strProxy& myString::strProxy::operator=(char c_val) {

    if(proxyObj.Pvalue->objCount > 1) {

        proxyObj.Pvalue = new strvalCount (proxyObj.Pvalue->valData);
    }

    proxyObj.Pvalue->valData[index_forProx] = c_val;

    return  *this;
}
