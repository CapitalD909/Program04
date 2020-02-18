#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "IntVector.h"
int main() {
    IntVector v1;
    cout << "Checking default size" << endl;
    cout << v1.size() << endl;
    cout << "Checking default capacity" << endl;
    cout << v1.capacity() << endl;
    cout << "Checking if empty" << endl;
    if (!v1.empty()){
        cout << "Is not empty" << endl;
    }
    else {
        cout << "Is empty" << endl;
    }
    cout << v1.at(0) << endl;
    cout << "Front of vector is " << v1.front() << endl;
    cout << "Back of vector is " << v1.back() << endl;
    v1.resize(40, 1);
    
    IntVector v2(10);
    cout << "Checking default size" << endl;
    cout << v2.size() << endl;
    cout << "Checking default capacity" << endl;
    cout << v2.capacity() << endl;
    cout << "Checking if empty" << endl;
    if (!v2.empty()){
        cout << "Is not empty" << endl;
    }
    else {
        cout << "Is empty" << endl;
    }
        cout << v2.at(9) << endl;
        cout << "Front of vector is " << v2.front() << endl;
        cout << "Back of vector is " << v2.back() << endl;
    v1.insert(4, 8);
    v1.erase(4);

    v2.resize(40, 1);

    
    IntVector v3(10, 5);
    cout << "Checking default size" << endl;
    cout << v3.size() << endl;
    cout << "Checking default capacity" << endl;
    cout << v3.capacity() << endl;
    cout << "Checking if empty" << endl;
    if (!v3.empty()){
        cout << "Is not empty" << endl;
    }
    else {
        cout << "Is empty" << endl;
    }
        cout << v3.at(9) << endl;
        cout << "Front of vector is " << v3.front() << endl;
        cout << "Back of vector is " << v3.back() << endl;
        v3.insert(4, 8);
        v3.erase(4);
    v3.resize(40, 1);




	return 0;
}