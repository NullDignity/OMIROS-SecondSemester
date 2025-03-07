#include <iostream>
using namespace std;

class MyClass {
    private: 
        string name = "NULL";
        int value = 0;

    public:
        void setName(string);
        void setValue(int);
        string getName(void) const;
        int getValue(void) const;
        void setAll(string, int);
        void print(void) const;
};