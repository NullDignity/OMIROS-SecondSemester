#include "MyClass.h"

int main() {

    MyClass class1, class2;
    string name1;
    int value1;

    cout << "\nInitial values for Object 1" << endl; // endl = \n
    cout << "_____________________________" << endl;
    class1.print();
    cout << "\nInitial values for Object 2" << endl;
    cout << "_____________________________" << endl;
    class2.print();

    cout << "\n\nGive a name for Object 1: ";
    cin >> name1;
    class1.setName(name1);
    class1.print();
    cout << "\nGive a value for Object 1: ";
    cin >> value1;
    class1.setValue(value1);
    class1.print();

    cout << "\n\nGive a name and a value for Object 2: ";
    cin >> name1 >> value1;
    class2.setAll(name1, value1);
    class2.print();

    return 0;
}