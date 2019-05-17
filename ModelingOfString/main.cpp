#include <iostream>
#include "mystring.h"
#include <string>


using namespace std;

int main()
{
    try {

         myString str1("Hello My Friend");
         myString str2(str1);
         myString str3(str2);
         str2 = str3;

// Testing

       // cout << "Exeptions" << endl;
       //myString strTest(0);
         cout << str1[0] << endl;
         cout << str1[1] << endl;
         cout << str1[2] << endl;

         str2[0] = 'A';
         str2[3] = 'B';

         cout << str2[0] << endl;
         cout << str2[1] << endl;
         cout << str2[2] << endl;
         cout << str2[3] << endl;

         cout << "length()" << endl;
         cout << str1.length() << endl;
         cout << str2.length() << endl;

         cout << "c_str()" << endl;
         const char *p = str1.c_str();
         cout << *p << endl;

         cout << "str1[1] = str2[6]" << endl;
         str1[1] = str2[6];
         cout << str1[1] << endl;

         cout << "FOR" << endl;
         for (int i=0; i < str1.length(); i++) {

             cout << str1[i] << endl;
         }

        } catch (const runtime_error &ex) {

            cout << "Runtime Error" << ex.what() << endl;

            cout << "Please enter the value again" << endl;
        }

    return 0;
}
