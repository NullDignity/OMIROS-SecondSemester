#include "MyClass.h"

void MyClass::setName(string name) {
    this->name = name;
}

string MyClass::getName(void) const {
    return this->name;
}

void MyClass::setValue(int value) {
    this->value = value;
}

int MyClass::getValue(void) const {
    return this->value;
}

void MyClass::setAll(string name, int value) {
    this->name = name;
    this->value = value;
}

void MyClass::print(void) const {
    cout << getName() << endl;
    cout << getValue() << endl;
}
